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


block_size = 30                         # size of each block in px
world_size = (15, 15)                   # the size of the plane (width, height) in terms of block_size
snake_spawn = (7, 7)                    # spawnpoint of the snake in the plane
default_mvdir = MovementDirection.DOWN  # the direction in which the snake moves in when the game starts
gametick_spacing = 5                    # after how many frames should the game udate
fps = 30                                # frame rate


pg.init()
screen = pg.display.set_mode((world_size[0] * block_size, world_size[1] * block_size))
pg.display.set_caption("Snake")
clock = pg.time.Clock()
running = True

snake_body = [snake_spawn]
apple = None
current_direction = default_mvdir
queue_direction = default_mvdir

gametick_spacing_count = 0

def draw():
    for s in snake_body:
        pg.draw.rect(screen, (0, 255, 0), (s[0] * block_size, s[1] * block_size, block_size, block_size))

    pg.draw.rect(screen, (40, 100, 40), (snake_body[0][0] * block_size, snake_body[0][1] * block_size, block_size, block_size))

    if apple != None:
        pg.draw.rect(screen, (255, 0, 0), (apple[0] * block_size, apple[1] * block_size, block_size, block_size))

def gameover():
    global running
    running = False
    print("GAME OVER")
    print("HIGH SCORE:", len(snake_body))

def game_tick():
    global snake_body
    global current_direction
    global apple
    
    if apple == None:
        new_apple = (random.randint(0, world_size[0] - 1), random.randint(0, world_size[1] - 1))
        while new_apple in snake_body:
            new_apple = (random.randint(0, world_size[0] - 1), random.randint(0, world_size[1] - 1))
        apple = new_apple

    current_direction = queue_direction
    next_block = tuple(a + b for a, b in zip(snake_body[0], current_direction.value))

    if not (0 <= next_block[0] < world_size[0] and 0 <= next_block[1] < world_size[1]):
        gameover()

    if next_block in snake_body:
        gameover()
    
    snake_body.insert(0, next_block)

    if len(snake_body) == world_size[0] * world_size[1]:
        gameover()
        print("YOU FINISHED THE GAME!!!!\n(if i got the condition right lol)")
    
    if apple == snake_body[0]:
        apple = None
    else:
        snake_body.pop()

def update_direction(mvdir):
    global queue_direction
    if len(snake_body) == 1 or mvdir.value != tuple(-x for x in current_direction.value):
        queue_direction = mvdir

def keyhandling(key):
        if key == pg.K_w:
            update_direction(MovementDirection.UP)
        elif key == pg.K_s:
            update_direction(MovementDirection.DOWN)
        elif key == pg.K_d:
            update_direction(MovementDirection.RIGHT)
        elif key == pg.K_a:
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

    if gametick_spacing_count > gametick_spacing:
        gametick_spacing_count = 0
        game_tick()
    else:
        gametick_spacing_count += 1
    
    clock.tick(fps)

pg.quit()
