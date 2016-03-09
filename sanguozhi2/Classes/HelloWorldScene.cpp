#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    

    Size winSize = Director::getInstance()->getWinSize();
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    
     m_pSprite = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_1"));
    // 给按钮添加触摸事件响应

    
    m_pEnemy = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_2"));
    
    ///button->setPosition(winSize.width/2,winSize.height/2);
    m_fAllTime = 0;

    addChild(rootNode);
    
    this->scheduleUpdate();


    return true;
}

void HelloWorld::update(float time)
{
    m_fAllTime += time;
    
    float xpos= m_pSprite->getPositionX();
    
    float xpos2 = m_pEnemy->getPositionX();

     m_pEnemy->setPositionX(xpos2-1);

     m_pSprite->setPositionX(xpos+1);
    
     Rect re = m_pEnemy->getBoundingBox();
    
    //碰撞检测
     if(re.containsPoint(m_pSprite->getPosition())){
    
         this->unscheduleUpdate();
         
     }
    
    
}
