import pygame
import sys
from pygame.locals import *
from random import *


class Ball(pygame.sprite.Sprite):
    def __init__(self,image,position,speed,bg_size):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(image).convert_alpha()
        self.rect = self.image.get_rect()
        position = self.rect.left, self.rect.top
        self.speed = speed
        self.width, self.height = bg_size[0], bg_size[1]

    def move(self):
        self.rect = self.rect.move(self.speed)
        if self.rect.right < 0:
            self.rect.left = self.width
        elif self.rect.left > self.width:
            self.rect.right = 0
        elif self.rect.bottom < 0:
            self.rect.top = self.height
        elif self.rect.top > self.height:
            self.rect.bottom = 0


def main():
    pygame.init()
    plane_image = 'ball.png'
    bg_image = 'background.png'
    bg_size = width, height = 487, 704
    screen = pygame.display.set_mode(bg_size)
    pygame.display.set_caption("demo")

    running = True
    background = pygame.image.load(bg_image).convert_alpha()
    balls = []
    for i in range(1):
        position = randint(0, width-400)
        speed = [randint(-10, 10),randint(-10, 10)]
        ball = Ball(plane_image, position, speed, bg_size)
        balls.append(ball)
    clock = pygame.time.Clock()

    while running:
        for events in pygame.event.get():
            if events.type == QUIT:
                sys.exit()

        screen.blit(background, (0, 0))

        for each in balls:
            each.move()
            screen.blit(each.image, each.rect)

        pygame.display.flip()
        clock.tick(36)


if __name__ == "__main__":
    main()
