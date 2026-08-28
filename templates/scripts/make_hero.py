#!/usr/bin/env python3
"""Compose a hero banner: background image + smooth bottom fade + title typography."""
import sys
import numpy as np
from PIL import Image, ImageDraw, ImageFont

def make_hero(src_path, out_path, title, subtitle,
              size=(1400, 600), fade_start=0.42, max_alpha=245,
              title_size=110, subtitle_size=32,
              title_color=(255, 255, 255), subtitle_color=(210, 213, 218),
              stroke_width=2, subtitle_stroke_width=3, stroke_fill=(0, 0, 0),
              bottom_margin=54):
    W, H = size
    bg = Image.open(src_path).convert("RGB")

    # cover-crop to target aspect ratio
    src_w, src_h = bg.size
    target_ratio = W / H
    src_ratio = src_w / src_h
    if src_ratio > target_ratio:
        new_w = int(src_h * target_ratio)
        x0 = (src_w - new_w) // 2
        bg = bg.crop((x0, 0, x0 + new_w, src_h))
    else:
        new_h = int(src_w / target_ratio)
        y0 = (src_h - new_h) // 2
        bg = bg.crop((0, y0, src_w, y0 + new_h))
    bg = bg.resize((W, H), Image.LANCZOS).convert("RGBA")

    # smooth eased alpha gradient (black), no hard edge
    fade_start_px = int(H * fade_start)
    ys = np.arange(H)
    t = np.clip((ys - fade_start_px) / (H - fade_start_px), 0, 1)
    t = t * t * (3 - 2 * t)  # smoothstep easing
    alpha_col = (t * max_alpha).astype(np.uint8)
    alpha = np.repeat(alpha_col[:, None], W, axis=1)
    overlay_arr = np.zeros((H, W, 4), dtype=np.uint8)
    overlay_arr[..., 3] = alpha
    overlay = Image.fromarray(overlay_arr, mode="RGBA")

    composed = Image.alpha_composite(bg, overlay)
    draw = ImageDraw.Draw(composed)

    title_font = ImageFont.truetype(
        "/home/nguyendimitri/.fonts/Neue_haas_grotesk/NeueHaasDisplay-Bold.ttf", title_size)
    subtitle_font = ImageFont.truetype(
        "/home/nguyendimitri/.fonts/Neue_haas_grotesk/NeueHaasDisplay-Roman.ttf", subtitle_size)

    def centered_text(y, text, font, fill, tracking=0, sw=stroke_width):
        if tracking:
            widths = [draw.textlength(c, font=font) for c in text]
            total = sum(widths) + tracking * (len(text) - 1)
            x = (W - total) / 2
            for c, w in zip(text, widths):
                draw.text((x, y), c, font=font, fill=fill,
                          stroke_width=sw, stroke_fill=stroke_fill)
                x += w + tracking
        else:
            bbox = draw.textbbox((0, 0), text, font=font)
            w = bbox[2] - bbox[0]
            x = (W - w) / 2
            draw.text((x, y), text, font=font, fill=fill,
                      stroke_width=sw, stroke_fill=stroke_fill)

    subtitle_bbox = draw.textbbox((0, 0), subtitle, font=subtitle_font)
    subtitle_h = subtitle_bbox[3] - subtitle_bbox[1]
    subtitle_y = H - bottom_margin - subtitle_h
    title_bbox = draw.textbbox((0, 0), title, font=title_font)
    title_h = title_bbox[3] - title_bbox[1]
    title_y = subtitle_y - title_h - 28

    centered_text(title_y, title, title_font, title_color)
    centered_text(subtitle_y, subtitle, subtitle_font, subtitle_color, tracking=2, sw=subtitle_stroke_width)

    composed.convert("RGB").save(out_path, quality=95)

if __name__ == "__main__":
    src, out, title, subtitle = sys.argv[1:5]
    make_hero(src, out, title, subtitle)
