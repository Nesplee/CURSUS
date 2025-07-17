<div align="center">

# 🍝 PHILOSOPHERS - Dining Philosophers Problem 🍝

</div>

<div align="center">
  <img src=".assets/Illu_philo1.jpg" alt="PHILOSOPHERS Illustration" width="100%"/>

### *I think, therefore I eat* 💭
</div>

<div align="center">

## 🎯 ABOUT 🎯

This project is an introduction to the basics of process threading, and how to work with mutexes.
The challenge is to solve the famous dining philosophers problem - making sure no philosopher dies of starvation.

#### 📖 [Read the subject here](.assets/Philo.en.pdf)

</div>

<div align="center">

# 📚 Program Components

</div>

### 1. Core Functions 🎯
- [`main.c`](main.c) - Program entry and simulation orchestration
- [`philosophers.h`](philosophers.h) - Header with structures and prototypes

### 2. Initialization & Cleanup 🔧
- [`init.c`](init.c) - Initialize philosophers, forks and mutexes
- [`parse.c`](parse.c) - Arguments parsing and validation

### 3. Philosophers Life Cycle 🔄
- [`routine.c`](routine.c) - Philosophers' main routine:
  - Eating (with forks handling)
  - Sleeping
  - Thinking
  - Single philosopher case handling

### 4. Monitoring & Safety 🔍
- [`monitoring.c`](monitoring.c) - Death checking and meal counting:
  - Check philosophers' death
  - Monitor meals count
  - Handle end conditions

### 5. Utils & Time Management ⚡
- [`utils.c`](utils.c) - Utility functions:
  - Time management (using gettimeofday)
  - Status printing with mutex protection
  - Number validation
  - String to integer conversion

<div align="center">

## 🎭 The Dining Philosophers

<img src=".assets/Illu_philo2.jpg" alt="PHILO Simulation" width="300px"/>

</div>

##### Each philosopher needs two forks to eat. They sit at a round table, sharing forks with their neighbors:
- 🤔 Think when they don't have forks
- 🍝 Eat when they have both forks
- 😴 Sleep after eating
- ⚰️ Die if they don't eat in time

##### Key challenges:
- Prevent deadlocks
- Avoid starvation
- Ensure thread safety
- Handle resource sharing


<div align="center">

## 🔍 Project Details

</div>

<div align="center">
  <img src=".assets/Illu_philo3.jpg" alt="PHILO Details" width="300px"/>
</div>

<div align="center">

| 🎯 Key Learning Outcomes | 🛠️ Skills Developed |
|:------------------------|:-------------------|
| • Thread management<br>• Mutex operations<br>• Race condition handling<br>• Resource sharing | • Unix<br>• Rigor<br>• Algorithms & AI<br>• Imperative Programming |

### ⏰ Hours Spent: ~45 hours

</div>

<div align="center">

## ⭐ Results

<img src=".assets/100.png" alt="PHILO Grade" width="200px"/>

### Validated on February 6, 2025

</div>
