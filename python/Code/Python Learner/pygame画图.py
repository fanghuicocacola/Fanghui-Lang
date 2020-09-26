import pygame
import sys
from pygame.locals import *
import math
pygame.init()

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
points = [(200, 50), (300, 100), (300, 75), (500, 75), (500, 25), (300, 25),(300, 0)]

size = width, height = 640, 480
screen = pygame.display.set_mode(size)
pygame.display.set_caption('fh-demo')
clock = pygame.time.Clock()
position = size[0]//2, size[1]//2
moving = False
while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()

        if event.type == MOUSEBUTTONDOWN:
            if event.button == 1:
                moving = True

        if event.type == MOUSEBUTTONUP:
            if event.button == 1:
                moving = False

    if moving == True:
        position = pygame.mouse.get_pos()
        print(position)


    screen.fill(WHITE)

    pygame.draw.polygon(screen, GREEN, points, 1)
    pygame.draw.circle(screen, BLUE, position, 125, 1)
    pygame.draw.ellipse(screen, BLACK, (100, 100, 400, 100), 1)
    pygame.draw.arc(screen, RED, (50, 50, 100, 100), 0, math.pi, 1)
    pygame.draw.aaline(screen,BLACK,(0, 0), (100, 300), 1)


    pygame.display.flip()

    clock.tick(10)
