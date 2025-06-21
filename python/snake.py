'''
a very simple and crudely-coded recreation of snake with pygame
'''

import pygame as pg
import random
from enum import Enum

class MovementDirection(Enum):
        UP = (0, -1)
        DOWN = (0, 1)
        RIGHT = (1, 0)
        LEFT = (-1, 0)

def get_opposite(mvdir):
    if mvdir == MovementDirection.UP:
        return MovementDirection.DOWN
    elif mvdir == MovementDirection.DOWN:
        return MovementDirection.UP
    elif mvdir == MovementDirection.RIGHT:
        return MovementDirection.LEFT
    elif mvdir == MovementDirection.LEFT:
        return MovementDirection.RIGHT


pg.init()
screen = pg.display.set_mode((450, 450))
pg.display.set_caption("Snake")
clock = pg.time.Clock()
running = True

snake_body = [(7, 7)]
apple = 0
current_direction = MovementDirection.DOWN
queue_direction = MovementDirection.DOWN

gametick_spacing_count = 0

def draw():
    for s in snake_body:
        pg.draw.rect(screen, (0, 255, 0), (s[0] * 30, s[1] * 30, 30, 30))

    pg.draw.rect(screen, (40, 100, 40), (snake_body[0][0] * 30, snake_body[0][1] * 30, 30, 30))

    if apple != 0:
        pg.draw.rect(screen, (255, 0, 0), (apple[0] * 30, apple[1] * 30, 30, 30))

def gameover():
    global running
    running = False
    print("GAME OVER")
    print("HIGH SCORE:", len(snake_body))

def game_tick():
    global snake_body
    global current_direction
    global apple
    
    if apple == 0:
        new_apple = (random.randint(0, 14), random.randint(0, 14))
        while new_apple in snake_body:
            new_apple = (random.randint(0, 14), random.randint(0, 14))
        apple = new_apple

    current_direction = queue_direction
    next_block = tuple(a + b for a, b in zip(snake_body[0], current_direction.value))

    if not (0 <= next_block[0] < 15) or not (0 <= next_block[1] < 15):
        gameover()

    if next_block in snake_body:
        gameover()
    
    snake_body.insert(0, next_block)

    if len(snake_body) == 15*15:
        gameover()
        print("YOU FINISHED THE GAME!!!!\n(if i got the condition right lol)")
    
    if apple == snake_body[0]:
        apple = 0
    else:
        snake_body.pop()

def update_direction(mvdir):
    global queue_direction
    if len(snake_body) == 1 or mvdir != get_opposite(current_direction):
        queue_direction = mvdir

def keyhandling(key):
        if key == pg.K_UP:
            update_direction(MovementDirection.UP)
        elif key == pg.K_DOWN:
            update_direction(MovementDirection.DOWN)
        elif key == pg.K_RIGHT:
            update_direction(MovementDirection.RIGHT)
        elif key == pg.K_LEFT:
            update_direction(MovementDirection.LEFT)
        

while running:
    for event in pg.event.get():
        if event.type == pg.KEYDOWN:
            keyhandling(event.key)
        
        if event.type == pg.QUIT:
            running = False

    screen.fill("grey")

    draw()
    
    pg.display.flip()

    if gametick_spacing_count > 2:
        gametick_spacing_count = 0
        game_tick()
    else:
        gametick_spacing_count += 1
    
    clock.tick(30)

pg.quit()
