#include "Player.h"
#include "Camera.h"
#include "CollisionHandler.h"


Player::Player(string i, int x, int y, int as) : Character(i, x, y, as) {
    speed = 1;
    jumpTime = JUMPTIME;
    jumpForce = JUMPFORCE;
    isJumping = false;
    isGrounded = true;

    
    rigidBody = new RigidBody();
    
    collider->setBuffer({-50,-80 ,35, 25 });
    
}

Player::~Player(){
    
    if (rigidBody) {
        delete[] rigidBody;
        rigidBody = 0;
    }
   
    
}

void Player::Update(){

    
    animation->Init(id, direction, nrFrames);
    animation->Update();
  
    rigidBody->Update();
    lastSafePosition.setX(p->getX());
    p->TranslateX(rigidBody->getDistance().getX());
    collider->set(p->getX(), p->getY(), tileSize, tileSize);

    if (CollisionHandler::colHandler.mapCollision(collider->getBox(), 3)== 1 || CollisionHandler::colHandler.mapCollision(collider->getBox(), 4) == 1) {
       p->setX(lastSafePosition.getX());
    }
    
    
    rigidBody->Update();
    lastSafePosition.setY(p->getY());
    p->TranslateY(rigidBody->getDistance().getY());
    collider->set(p->getX(), p->getY(), tileSize, tileSize);
    if (CollisionHandler::colHandler.mapCollision(collider->getBox(), 1)) {
        p->setY(lastSafePosition.getY());
    }

    if (CollisionHandler::colHandler.mapCollision(collider->getBox(),2)) {
        isGrounded = true;
        p->setY(lastSafePosition.getY());
    }
    else { isGrounded = false; }
    
    origin->setX(p->getX() + playerSize);
    origin->setY(p->getY() + playerSize);

    switch (KeyboardInput::key.xkey) {
    case false:
        speed = 3;
        id = "WALK";
        nrFrames = WALK;
        break;
    case true:
        speed = 5;
        id = "RUN";
        nrFrames = RUN;
        break;
    }
    if (KeyboardInput::key.left == true && !isJumping ) {
        rigidBody->applyForceX(-speed);
        direction = LEFT;
    }
    else if (KeyboardInput::key.right == true && !isJumping) {
         rigidBody->applyForceX(speed);
         direction = RIGHT;
    }
    else {
        id = "WAIT";
        nrFrames = WAIT;
        speed = 0;
        rigidBody->unSetForce();
    }

    if (KeyboardInput::key.up && isGrounded) {
        id = "JUMP";
        nrFrames = JUMP;
        isJumping = true;
        isGrounded = false;
        rigidBody->applyForceY(-1 * jumpForce);
    }
    if (KeyboardInput::key.up && isJumping && !isGrounded && jumpTime > 0) {
        id = "JUMP";
        nrFrames = JUMP;
        jumpTime -= 0.5;
        if (jumpTime <= 0) {
            KeyboardInput::key.up = false;
            rigidBody->unSetForce();
        }
        rigidBody->applyForceY(-1 * jumpForce);
    }
    else {
        isJumping = false;
        jumpTime = JUMPTIME;
    }
 
}

void Player::Render() {
    animation->Render(p, 1);

    Position cam = Camera::camera.getPosition();
    SDL_Rect box = collider->getBox();
    box.x -= cam.getX();
    box.y -= cam.getY();
    SDL_RenderDrawRect(Game::renderer, &box);
}

void Player::Clean() {
    TextureManager::tex.Drop(id);
}