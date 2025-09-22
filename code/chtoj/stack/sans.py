import pygame, sys, random

# Initialize
pygame.init()
WIDTH, HEIGHT = 600, 400
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

# Colors
WHITE = (255,255,255)
RED = (255,0,0)
BLACK = (0,0,0)

# Player
player_size = 20
player = pygame.Rect(WIDTH//2, HEIGHT//2, player_size, player_size)
speed = 5
hp = 10

# Bones
bones = []
bone_timer = 0
BONE_SPEED = 6

def spawn_bone():
    side = random.choice(["top","bottom","left","right"])
    if side == "top":
        rect = pygame.Rect(random.randint(0, WIDTH-20), 0, 20, 10)
        vel = (0,BONE_SPEED)
    elif side == "bottom":
        rect = pygame.Rect(random.randint(0, WIDTH-20), HEIGHT-10, 20, 10)
        vel = (0,-BONE_SPEED)
    elif side == "left":
        rect = pygame.Rect(0, random.randint(0, HEIGHT-20), 10, 20)
        vel = (BONE_SPEED,0)
    else:
        rect = pygame.Rect(WIDTH-10, random.randint(0, HEIGHT-20), 10, 20)
        vel = (-BONE_SPEED,0)
    return [rect, vel]

# Game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit(); sys.exit()

    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP] and player.top > 0: player.y -= speed
    if keys[pygame.K_DOWN] and player.bottom < HEIGHT: player.y += speed
    if keys[pygame.K_LEFT] and player.left > 0: player.x -= speed
    if keys[pygame.K_RIGHT] and player.right < WIDTH: player.x += speed

    # Spawn bones
    bone_timer += 1
    if bone_timer > 30:  # every 30 frames
        bones.append(spawn_bone())
        bone_timer = 0

    # Update bones
    for b in bones:
        b[0].x += b[1][0]
        b[0].y += b[1][1]

    # Collision
    for b in bones:
        if player.colliderect(b[0]):
            hp -= 1
            bones.remove(b)
            break

    # Draw
    screen.fill(BLACK)
    pygame.draw.rect(screen, RED, player)
    for b in bones:
        pygame.draw.rect(screen, WHITE, b[0])

    # HP
    font = pygame.font.SysFont(None, 30)
    text = font.render(f"HP: {hp}", True, WHITE)
    screen.blit(text, (10,10))

    pygame.display.flip()
    clock.tick(60)