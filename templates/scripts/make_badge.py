#!/usr/bin/env python3
"""Generate a small rounded-rect outline badge: bordeaux border, transparent bg, bordeaux/white text."""
import sys
from PIL import Image, ImageDraw, ImageFont

SCALE = 4  # supersample for crisp rounded corners at small display size

def make_badge(text, out_path, font_size=13, pad_x=12, pad_y=5,
               border_color=(99, 33, 42, 255), text_color=(210, 160, 165, 255),
               radius=6, stroke=1.4):
    font = ImageFont.truetype(
        "/home/nguyendimitri/.fonts/Neue_haas_grotesk/NeueHaasDisplay-Bold.ttf", font_size * SCALE)
    tmp = Image.new("RGBA", (10, 10))
    d = ImageDraw.Draw(tmp)
    bbox = d.textbbox((0, 0), text, font=font)
    tw, th = bbox[2] - bbox[0], bbox[3] - bbox[1]

    W = tw + pad_x * 2 * SCALE
    H = th + pad_y * 2 * SCALE
    im = Image.new("RGBA", (int(W), int(H)), (0, 0, 0, 0))
    draw = ImageDraw.Draw(im)
    draw.rounded_rectangle(
        [stroke * SCALE / 2, stroke * SCALE / 2, W - stroke * SCALE / 2, H - stroke * SCALE / 2],
        radius=radius * SCALE, outline=border_color, width=int(stroke * SCALE))
    draw.text(((W - tw) / 2 - bbox[0], (H - th) / 2 - bbox[1]), text, font=font, fill=text_color)
    im.save(out_path)
    print(out_path, im.size)

if __name__ == "__main__":
    make_badge(sys.argv[1], sys.argv[2])
