#include "GritGameEngine.cpp"

// Start the game code from here

int collectioncount = 0;
int MonsterSpeed = 50;



int Game()
{
    srand(time(0));
    Application::application_initialize();
    InputController playercontroller = InputController();
    Smart_Ptr<GameObject> Monster = GetGameObjectByName("Monster");
    getphysicscomponent(Monster)->setphysics(true);
    Smart_Ptr<GameObject> player = GetGameObjectByName("Pranav");
    Smart_Ptr<GameObject> gameoverscreen = GetGameObjectByName("GameOver");
    Smart_Ptr<GameObject> winscreen = GetGameObjectByName("Win");
    auto grc = getrendercomponent(gameoverscreen);
    grc->setrendering(false);
    auto wrc = getrendercomponent(winscreen);
    wrc->setrendering(false);
    auto player_physicscomp = getphysicscomponent(player);
    player_physicscomp->setphysics(true);
    auto monster_physicscomp = getphysicscomponent(Monster);
    //Delay* timergameover = new Delay(2);
    std::function<void(collision* other)> MonsterCollisionEventHandle = [](collision* other)  
    {
        Smart_Ptr<GameObject> otherobject(other->WeakGO);
        if (otherobject->getname() == "Pranav")
        {
            getrendercomponent(GetGameObjectByName("GameOver"))->setrendering(true);
        }
    };
    std::function<void(collision* other)> PlayerCollisionEventHandle = [](collision* other)
    {
        Smart_Ptr<GameObject> otherobject(other->WeakGO);
        if (otherobject->getname() == "Green")
        {
            auto rc = getrendercomponent(otherobject);
            if (collectioncount == 2)
            {
                getrendercomponent(GetGameObjectByName("Win"))->setrendering(true);
                rc->setrendering(false);
            }
            else
            {
                float x = rand() % 650 + (-350);
                float y = rand() % 650 + (-350);
                rc->setrendering(false);
                otherobject->setpos(Point2D{ x, y });
                collectioncount++;
                rc->setrendering(true);
            }
            
        }
        if (otherobject->getname() == "Red")
        {
            if (MonsterSpeed < 100)
                MonsterSpeed += 10;
            else
                getrendercomponent(otherobject)->setrendering(false);
        }
    };
    getcollisioncomponent(Monster)->AddCollisionEvent(MonsterCollisionEventHandle);
    getcollisioncomponent(player)->AddCollisionEvent(PlayerCollisionEventHandle);
    char a = 'a';
    while (a != 'q')   // This is the game loop
    {
        if (playercontroller.GetKeyPressQ())  //press q
        {
            Application::application_end();
            a ='q';
            break;
        }
        float fx = 500;
        if (playercontroller.GetKeyPressD())
        {
            player_physicscomp->physics->force = { fx,0};
        }
        else if (playercontroller.GetKeyPressS())
        {
            player_physicscomp->physics->force = { 0,-fx };
        }
        else if (playercontroller.GetKeyPressW())
        {
            player_physicscomp->physics->force = { 0,fx };
        }
        else if (playercontroller.GetKeyPressA())
        {
            player_physicscomp->physics->force = { -fx,0 };
        }
        else
        {
            player_physicscomp->physics->force = { 0,0 };
        }
        Application::application_update();
        monster_physicscomp->physics->moveto(player, MonsterSpeed);
    }
    return 0;
}

