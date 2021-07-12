#include "game.hpp"

CGame::CGame ( std::vector<std::vector<char>>& map ) : m_map ( map ), gameOn ( false ), End ( false ),
                level_flag (0), progress_flag(0) {};

CGame::~CGame () {
    CGame::cleanCharacters();

    delete m_player;
};

CGame& CGame::cleanCharacters(){
    for(auto it = m_enemie.begin(); it != m_enemie.end(); it++){
        delete *it;
    }
    for(auto it2 = m_chest.begin(); it2 != m_chest.end(); it2++){
        delete *it2;
    }
    for(auto it3 = m_trap.begin(); it3 != m_trap.end(); it3++ ){
        delete *it3;
    }

    m_enemie.clear();
    m_trap.clear();
    m_chest.clear();

    return *this;
}

CGame& CGame::runGame(){
    gameOn = true;
    return *this;
}

CGame& CGame::endApp() {
    End = true;
    return *this;
}

CGame& CGame::stopGame(){
    gameOn = false;
    return *this;
}

CGame& CGame::setPlayer( CPlayer * player ){
    delete m_player;
    m_player = player;
    return *this;
}

CGame& CGame::addEnemie( CEnemies * enemie ){
    m_enemie.push_back( enemie );
    return *this;
}

CGame& CGame::addChest( const int& x, const int& y ){
    if( level_flag == 1){
        CBack_pack* tmp_backpack = new CBack_pack ( 4 );

        tmp_backpack->addItem( new CPotionH ( "Drug", 1, 2, 10));
        tmp_backpack->addItem( new CPotionL( "Kozel", 2, 4, 100 ));

        std::set<std::string> tmp_set;
        tmp_set.insert("one thousand nine hundred and eighty five");
        tmp_set.insert("one thousand nine hundred eighty five");
        tmp_set.insert("1985");

        m_chest.push_back( new CChest ( x, y, tmp_backpack, tmp_set, "When was the first edition of the C++ released?") );
    }
    if ( level_flag == 2 ){
        CBack_pack* tmp_backpack = new CBack_pack ( 10 );

        tmp_backpack->addItem( new CSword( "xvagner", 4, 1, 8 ));
        tmp_backpack->addItem( new CPotionL( "Staropramen", 2, 4, 150 ));

        std::set<std::string> tmp_set;
        tmp_set.insert("Tony Stark");
        tmp_set.insert("tony stark");

        m_chest.push_back( new CChest ( x, y, tmp_backpack, tmp_set, "What is the actual name of the Iron Man?") );
    }
    if (  level_flag == 3 ){
        CBack_pack* tmp_backpack = new CBack_pack ( 6 );

        tmp_backpack->addItem( new CPotionD( "Gul'dan drink", 5, 3, 5 ));
        tmp_backpack->addItem( new CPotionH ( "Burger", 1, 2, 10 ));

        std::set<std::string> tmp_set;
        tmp_set.insert("Russia");
        tmp_set.insert("russia");

        m_chest.push_back( new CChest ( x, y, tmp_backpack, tmp_set, "What is the name the biggest country in the world?") );
    }
    if (  level_flag == 4 ){
        CBack_pack* tmp_backpack = new CBack_pack ( 15 );

        tmp_backpack->addItem( new CSword( "Valgrind", 10, 1, 15 ));

        std::set<std::string> tmp_set;
        tmp_set.insert("Prague");
        tmp_set.insert("prague");

        m_chest.push_back( new CChest ( x, y, tmp_backpack, tmp_set, "Where is located FIT? (city)") );
    }
    if (  level_flag == 5 ){
        CBack_pack* tmp_backpack = new CBack_pack ( 10 );

        tmp_backpack->addItem( new CPotionH ( "Drug", 2, 2, 15));
        tmp_backpack->addItem( new CPotionL( "Staropramen", 4, 4, 250 ));
        tmp_backpack->addItem( new CPotionD( "Gul'dan drink", 4, 3, 4 ));

        std::set<std::string> tmp_set;
        tmp_set.insert("Kiev");
        tmp_set.insert("Kyiv");
        tmp_set.insert("kiev");
        tmp_set.insert("kyiv");

        m_chest.push_back( new CChest ( x, y, tmp_backpack, tmp_set, "Where is the capital of Ukraine? (city)") );
    }

    return *this;
}

CGame& CGame::addChest( CChest * chest ){
    m_chest.push_back( chest );
    return *this;
}

CGame& CGame::addTrap( const int& x, const int& y ){
    if( level_flag == 1){
        m_trap.push_back( new CBomb ( x, y, 10) );
    }
    if ( level_flag == 2 ){
        m_trap.push_back( new CSnare ( x, y, 5) );
    }
    if (  level_flag == 3 ){
        m_trap.push_back( new CThorm ( x, y, 5) );
    }
    if (  level_flag == 4 ){
        m_trap.push_back( new CBomb ( x, y, 10) );
    }
    if (  level_flag == 5 ){
        m_trap.push_back( new CThorm ( x, y, 5) );
    }
    return *this;
}

CGame& CGame::addTrap ( CTrap* trap ){
    m_trap.push_back ( trap );
    return *this;
}

CGame& CGame::readProgress ( ){
    std::ifstream read_file;
    read_file.open(m_savings[0], std::ios::in);

    if( !read_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string line;
    int counter = 1, tmp_health = 0, tmp_damage = 0, tmp_level = 0, tmp_exp = 0, tmp_x = 0, tmp_y = 0, tmp_equip_damage = 0;
    char tmp_dir;

    getline(read_file, line);
    level_flag = std::stoi(line);

    getline(read_file, line);
    progress_flag = std::stoi(line);

    while(getline(read_file, line)){

        switch ( counter ) {
            case 1:
                tmp_health = std::stoi(line);
                break;
            case 2:
                tmp_damage = std::stoi(line);
                break;
            case 3:
                tmp_equip_damage = std::stoi(line);
                break;
            case 4:
                tmp_level = std::stoi(line);
                break;
            case 5:
                tmp_exp = std::stoi(line);
                break;
            case 6:
                tmp_x = std::stoi(line);
                break;
            case 7:
                tmp_y = std::stoi(line);
                break;
            case 8:
                tmp_dir = line.front();
                break;
            default:
                break;
        }

        counter++;
    }

    CGame::setPlayer ( new CPlayer ( tmp_x, tmp_y, tmp_health, tmp_level, tmp_damage, tmp_exp, tmp_dir, tmp_equip_damage ) );

    read_file.close();

    return *this;
}

CGame& CGame::readCurrentWorld ( ){
    std::fstream my_file;
    my_file.open( m_savings[2], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string new_line;
    int column = 0;

    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
    return *this;
}

CGame& CGame::readBackPack ( ){
    std::ifstream read_file;
    read_file.open(m_savings[1], std::ios::in);

    if( !read_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string line;
    bool tmp_equip = false;
    int counter = 1, tmp_id = 0, tmp_item_size = 0, tmp_parameter = 0, tmp_size = 0;
    std::string tmp_name;

    getline(read_file, line);
    tmp_size = std::stoi(line);
    getline(read_file, line);

    CBack_pack * tmp_backpack = new CBack_pack( tmp_size );

    if( read_file.eof() ){
        m_player->setBackPack( tmp_backpack );
        return *this;
    }
    
    while(getline(read_file, line)){

        switch ( counter ) {
            case 1:
                tmp_name = line;
                break;
            case 2:
                tmp_id = std::stoi(line);
                break;
            case 3:
                if( std::stoi( line ) == 1 )
                    tmp_equip = true;
                break;
            case 4:
                tmp_item_size = std::stoi(line);
                break;
            case 5:
                tmp_parameter = std::stoi(line);
                break;
            default:
                break;
        }

        if( counter % 5 == 0 ){
            if( tmp_id == 1 ){
                tmp_backpack->addItem( new CSword ( tmp_name, tmp_item_size, tmp_id, tmp_parameter, tmp_equip));
            }
            if( tmp_id == 2 ){
                tmp_backpack->addItem( new CPotionH ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
            }
            if ( tmp_id == 3 ){
                tmp_backpack->addItem( new CPotionD ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
            }
            if( tmp_id == 4 ){
                tmp_backpack->addItem( new CPotionL ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
            }
            counter %= 5;
        }
        
        counter++;
    }

    m_player->setBackPack( tmp_backpack );

    read_file.close();

    return *this;
}

CGame& CGame::readEnemie ( ){
    std::ifstream read_file;
    read_file.open(characters_save[0], std::ios::in);

    if( !read_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string line;
    int counter = 1, tmp_health = 0, tmp_damage = 0, tmp_exp = 0, tmp_x = 0, tmp_y = 0;
    char tmp_dir = 0;

    while(getline(read_file, line)){

        int power = 0;

        switch ( counter ) {
            case 1:
                if( line == "nullptr") {
                    CGame::addEnemie( nullptr );
                    counter = 0;
                    break;
                }
                tmp_health = std::stoi(line);
                break;
            case 2:
                tmp_damage = std::stoi(line);
                break;
            case 3:
                tmp_exp = std::stoi(line);
                break;
            case 4:
                tmp_dir = line.front();
                break;
            case 5:
                tmp_x = std::stoi(line);
                break;
            case 6:
                tmp_y = std::stoi(line);
                break;
            default:
                break;
        }

        if( counter % 6 == 0 && counter != 0){
            if( tmp_dir == 'B' ){
                CGame::addEnemie( new CBoss ( tmp_x, tmp_y, tmp_health, tmp_damage, tmp_exp, tmp_dir ) );
            }
            if( tmp_dir == 'D' ){
                CGame::addEnemie( new CDragon ( tmp_x, tmp_y, tmp_health, tmp_damage, tmp_exp, tmp_dir ) );
            }
            if( tmp_dir == 'P' ){
                CGame::addEnemie( new CPunk ( tmp_x, tmp_y, tmp_health, tmp_damage, tmp_exp, tmp_dir ) );
            }
            if( tmp_dir == 'S' ){
                CGame::addEnemie( new CSoldier ( tmp_x, tmp_y, tmp_health, tmp_damage, tmp_exp, tmp_dir ) );
            }
            if( tmp_dir == 'W' ){
                CGame::addEnemie( new CBoarW140 ( tmp_x, tmp_y, tmp_health, tmp_damage, tmp_exp, tmp_dir) );
            }
            counter %= 6;
        }

        counter++;
    }
    read_file.close();
    return *this;
}

CGame& CGame::readTrap ( ){
    std::ifstream read_file;
    read_file.open(characters_save[2], std::ios::in);

    if( !read_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string line;
    int tmp_id = 0, tmp_x = 0, tmp_y = 0, tmp_damage = 0, counter = 1;

    while(getline( read_file, line )){

        switch ( counter ){
            case 1:
                if( line == "nullptr"){
                    CGame::addTrap( nullptr );
                    counter = 0;
                    break;
                }
                tmp_id = std::stoi( line );
                break;
            case 2:
                tmp_x = std::stoi( line );
                break;
            case 3:
                tmp_y = std::stoi( line );
                break;
            case 4:
                tmp_damage = std::stoi( line );
                break;
            default:
                break;
        }

        if( counter % 4 == 0 && counter != 0){
            if ( tmp_id == 1 ){
                CGame::addTrap( new CBomb ( tmp_x, tmp_y, tmp_damage) );
            }   
            if( tmp_id == 2){
                CGame::addTrap( new CSnare ( tmp_x, tmp_y, tmp_damage) );
            }
            if( tmp_id == 3 ){
                CGame::addTrap( new CThorm ( tmp_x, tmp_y, tmp_damage) );
            }
        }

        counter++;
    }
    return *this;
}

CGame& CGame::readChest ( ){
    std::ifstream read_file;
    read_file.open(characters_save[1], std::ios::in);

    if( !read_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return *this;
    }

    std::string line, tmp_mystery, tmp_name;
    bool tmp_opened = false;
    int tmp_x = 0, tmp_y = 0, counter = 1, size_answers = 0;
    std::set<std::string> tmp_answer;
    CBack_pack * tmp_inventory = nullptr;

    while( getline( read_file, line ) ){

        switch ( counter ){
        case 1:
            if( line == "nullptr" ){
                CGame::addChest ( nullptr );
                counter = 0;
                break;
            }

            tmp_x = std::stoi ( line ); 
            break;
        case 2:
            tmp_y = std::stoi ( line );
            break;
        case 3:
            if( std::stoi( line ) == 1 ){
                tmp_opened = true;
            }
            break;
        case 4:
            tmp_mystery = line;
            break;
        case 5:
            size_answers = std::stoi ( line );
            for ( int i = 1; i < size_answers; i++){
                getline( read_file, line );
                tmp_answer.insert( line );
            }
            break;
        case 6:
            int counter2 = 1, tmp_id = 0, tmp_item_size = 0, tmp_parameter = 0, tmp_size = 0, amount_of_items = 0;
            getline(read_file, line);
            tmp_size = std::stoi(line);

            getline(read_file, line);
            amount_of_items = std::stoi(line);
            amount_of_items *= 5;

            delete tmp_inventory;
            tmp_inventory = nullptr;
            CBack_pack * tmp_inventory = new CBack_pack( tmp_size );

            while( amount_of_items != 0 ){

                getline(read_file, line);

                switch ( counter2 ){
                    case 1:
                        tmp_name = line;
                        break;
                    case 2:
                        tmp_id = std::stoi(line);

                        getline(read_file, line);
                        amount_of_items--;
                        counter2++;
                        break;
                    case 4:
                        tmp_item_size = std::stoi(line);
                        break;
                    case 5:
                        tmp_parameter = std::stoi(line);
                        break;
                    default:
                        break;
                }

                if( counter2 % 5 == 0 ){
                    if( tmp_id == 1 ){
                        tmp_inventory->addItem( new CSword ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
                    }
                    if( tmp_id == 2 ){
                        tmp_inventory->addItem( new CPotionH ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
                    }
                    if ( tmp_id == 3 ){
                        tmp_inventory->addItem( new CPotionD ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
                    }
                    if( tmp_id == 4 ){
                        tmp_inventory->addItem( new CPotionL ( tmp_name, tmp_item_size, tmp_id, tmp_parameter));
                    }
                    counter2 %= 5;
                }

                amount_of_items--;
                counter2++;
            }
            CGame::addChest ( new CChest ( tmp_x, tmp_y, tmp_inventory, tmp_answer, tmp_mystery, tmp_opened ) );
            break;
        }

        if( counter % 6  == 0 && counter != 0 ){
            counter %= 6;
        }

        counter++;
    }
    read_file.close();
    return *this;
}

CGame& CGame::trapUsing (const int& x, const int&y ){
    if ( !m_trap[level_flag - 1] || x != m_trap[level_flag - 1]->getPosX() || y != m_trap[level_flag - 1]->getPosY()){
        return *this;
    }

    m_trap[level_flag - 1]->effectOnPlayer( *m_player );
    delete m_trap[level_flag - 1];
    m_trap[level_flag - 1] = nullptr;

    system ( "clear" );
    char tmp = 0;
    std::cout << "You got into trap" << std::endl << "Enter something to continue: " << std::endl;
    std::cin >> tmp;

    return *this;
}

bool CGame::getGameOn() const{
    return gameOn;
}

bool CGame::getEnd() const{
    return End;
}

void CGame::newGame( ){
    level_flag = 1;
    progress_flag = 1;

    std::fstream my_file;
    my_file.open( m_levels[level_flag - 1], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    std::string new_line;
    int column = 0;
    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            if(new_line[raw] == '>'){
                CGame::setPlayer ( new CPlayer (raw, column) );
            }
            if( new_line[raw] == 'B' ){
                CGame::addEnemie( new CBoss ( raw, column, 80, 25, 500,  'B') );
            }
            if( new_line[raw] == 'D' ){
                CGame::addEnemie( new CDragon ( raw, column, 40, 15, 350,  'D') );
            }
            if( new_line[raw] == 'P' ){
                CGame::addEnemie( new CPunk ( raw, column, 20, 8, 200,  'P') );
            }
            if( new_line[raw] == 'S' ){
                CGame::addEnemie( new CSoldier ( raw, column, 30, 12, 300,  'S') );
            }
            if( new_line[raw] == 'W' ){
                CGame::addEnemie( new CBoarW140 ( raw, column, 8, 5, 150,  'W') );
            }
            if( new_line[raw] == '$'){
                CGame::addChest ( raw, column );
            }
            if( new_line[raw] == '!' ){
                CGame::addTrap ( raw, column) ;
                new_line[raw] = ' ';
            }
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
}

void CGame::saveGame(  ){
    CGame::savePlayer();
    CGame::saveEnemies();
    CGame::saveTrap();
    CGame::saveChest();
    CGame::saveLevel();
}

void CGame::saveLevel( ){
    std::ofstream output_file;

    output_file.open( levels_save[level_flag - 1], std::ios::out);

    if( !output_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    for( auto it1 = 0; it1 != m_map.size(); it1++ ){
        for(auto it2 = 0; it2 != m_map[it1].size(); it2++ ){
            output_file << m_map[it1][it2];
        }
        output_file << '\n';
    }

    output_file.close();
}

void CGame::saveEnemies( ){
    std::ofstream output_file;

    output_file.open( characters_save[0], std::ios::out);
    
    if( !output_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    for( const auto & it : m_enemie ){
        if( it == nullptr ){
            output_file << "nullptr" << std::endl;
            continue;
        }
        it->saveEnemie( output_file );
        output_file << std::endl;
    }

    output_file.close();
}

void CGame::saveChest(){
    std::ofstream output_file;

    output_file.open( characters_save[1], std::ios::out);

    if( !output_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    for( const auto& it : m_chest){
        if( it == nullptr ){
            output_file << "nullptr" << std::endl;
            continue;
        }
        it->saveChest( output_file );
        output_file << std::endl;
    }

    output_file.close();
}

void CGame::saveTrap (){
    std::ofstream output_file;

    output_file.open( characters_save[2], std::ios::out);

    if( !output_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    for( const auto & it : m_trap ){
        if( it == nullptr){
            output_file << "nullptr" << std::endl;
            continue;
        }
        it->saveTrap( output_file );
    }

    output_file.close();
}

void CGame::savePlayer (){
    std::ofstream progress_file, backpack_file, world_file;

    progress_file.open(m_savings[0], std::ios::out);
    backpack_file.open( m_savings[1], std::ios::out);
    world_file.open(m_savings[2], std::ios::out);

    if( !progress_file || !backpack_file || !world_file ){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    progress_file << level_flag << std::endl << progress_flag << std::endl;
    m_player->saveProgress ( progress_file, backpack_file );

    for( auto it1 = 0; it1 != m_map.size(); it1++ ){
        for(auto it2 = 0; it2 != m_map[it1].size(); it2++ ){
            world_file << m_map[it1][it2];
        }
        world_file << '\n';
    }

    world_file.close();
    progress_file.close();
    backpack_file.close();
}

void CGame::loadSavedGame( ){
    CGame::cleanCharacters();
    CGame::readProgress();
    CGame::readBackPack();
    CGame::readCurrentWorld();
    CGame::readEnemie();
    CGame::readTrap();
    CGame::readChest();
}

void CGame::loadNewLevel( ){
    level_flag += 1;
    progress_flag += 1;

    std::fstream my_file;
    my_file.open( m_levels[level_flag - 1], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    std::string new_line;
    int column = 0;
    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            if(new_line[raw] == '>' || new_line[raw] == '<' || new_line[raw] == '^'){
                if( m_player ){
                    m_player->movement( raw, column, new_line[raw]);
                }
                else{
                    CGame::setPlayer ( new CPlayer (raw, column) );
                }
            }
            if( new_line[raw] == 'B' ){
                CGame::addEnemie( new CBoss ( raw, column, 80, 25, 500,  'B') );
            }
            if( new_line[raw] == 'D' ){
                CGame::addEnemie( new CDragon ( raw, column, 40, 15, 350,  'D') );
            }
            if( new_line[raw] == 'P' ){
                CGame::addEnemie( new CPunk ( raw, column, 20, 8, 200,  'P') );
            }
            if( new_line[raw] == 'S' ){
                CGame::addEnemie( new CSoldier ( raw, column, 30, 12, 300,  'S') );
            }
            if( new_line[raw] == 'W' ){
                CGame::addEnemie( new CBoarW140 ( raw, column, 8, 5, 150,  'W') );
            }
            if( new_line[raw] == '$'){
                CGame::addChest ( raw, column );
            }
            if( new_line[raw] == '!' ){
                CGame::addTrap ( raw, column ) ;
                new_line[raw] = ' ';
            }
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
}

void CGame::loadPreviousLevel() {
    level_flag -= 1;

    std::fstream my_file;
    my_file.open( levels_save[level_flag - 1], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    std::string new_line;
    int column = 0;
    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            if(new_line[raw] == '>' || new_line[raw] == '<' || new_line[raw] == '^'){
                if( m_player ){
                    m_player->movement( raw, column, new_line[raw]);
                }
                else{
                    CGame::setPlayer ( new CPlayer ( raw, column ) );
                }
            }
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
}

void CGame::loadNextLevel ( ){
    level_flag += 1;
    std::fstream my_file;
    my_file.open( levels_save[level_flag - 1], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    std::string new_line;
    int column = 0;
    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            if(new_line[raw] == '>' || new_line[raw] == '<' || new_line[raw] == '^'){
                if( m_player ){
                    m_player->movement( raw, column, new_line[raw]);
                }
                else{
                    CGame::setPlayer ( new CPlayer ( raw, column ) );
                }
            }
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
}

void CGame::loadCurrentLevel ( ){
    std::fstream my_file;
    my_file.open( levels_save[level_flag - 1], std::ios::in);

    if(!my_file){
        system("clear");
        std::cout << "Don't open the file" << std::endl;
        return;
    }

    std::string new_line;
    int column = 0;
    while(getline(my_file, new_line)){
        std::vector<char> tmp;
        for(auto raw = 0; raw < new_line.size(); raw++){
            if(new_line[raw] == '>' || new_line[raw] == '<' || new_line[raw] == '^'){
                if( m_player ){
                    m_player->movement( raw, column, new_line[raw]);
                }
                else{
                    CGame::setPlayer ( new CPlayer ( raw, column ) );
                }
            }
            tmp.push_back(new_line[raw]);
        }
        m_map.push_back(tmp);
        column++;
    }

    my_file.close();
}

void CGame::printMenu(std::ostream& os){
    os << "MAIN MENU:" << std::endl << "Press 1 to RUN NEW GAME" << std::endl << "Press 2 to RUN SAVED GAME" << std::endl
        << "Press 3 to SAVE GAME" << std::endl << "Press 4 to SAVE&EXIT GAME" << std::endl << "Press 5 to EXIT GAME" << std::endl;
}

void CGame::specifyChoice (const char& choice){
    if( choice == '1' ){
        m_map.clear();
        CGame::newGame();
        CGame::runGame();
        return;
    }
    if( choice == '2'){
        std::fstream savedProgress;
        savedProgress.open( m_savings[0], std::ios::in);
        if ( savedProgress.peek() == std::ifstream::traits_type::eof() ){
            savedProgress.close();
            return;
        }
        savedProgress.close();
        m_map.clear();
        CGame::loadSavedGame();
        CGame::runGame();
        return;
    }
    if ( choice == '3'){
        if( !m_player ){
            return;
        }
        CGame::saveGame();
        m_map.clear();
        CGame::loadSavedGame();
        CGame::runGame();
        return;
    }
    if ( choice == '4'){
        if( m_map.empty() ){
            CGame::endApp();
            return;
        }
        CGame::saveGame();
        CGame::endApp();
        return;
    }
    if ( choice == '5'){
        CGame::endApp();
        return;
    }
}

bool CGame::detected(char& check){
    if( m_map[m_player->getPosY() + 1][m_player->getPosX()] != ' ' && m_map[m_player->getPosY() + 1][m_player->getPosX()] != '#'){
            check = m_map[m_player->getPosY() + 1][m_player->getPosX()];
            return true;
        }
    if( m_map[m_player->getPosY() - 1][m_player->getPosX()] != ' ' && m_map[m_player->getPosY() - 1][m_player->getPosX()] != '#' ){
        check = m_map[m_player->getPosY() - 1][m_player->getPosX()];
        return true;
    }
    if( m_map[m_player->getPosY()][m_player->getPosX() - 1] != ' ' && m_map[m_player->getPosY()][m_player->getPosX() - 1] != '#' ){
        check = m_map[m_player->getPosY()][m_player->getPosX() - 1];
        return true;
    }
    if (m_map[m_player->getPosY()][m_player->getPosX() + 1] != ' ' && m_map[m_player->getPosY()][m_player->getPosX() + 1] != '#'){
        check = m_map[m_player->getPosY()][m_player->getPosX() + 1];
        return true;
    }
    return false;
}

void CGame::drawMap ( ) {
    system("clear");
    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++){ 
            std::cout << m_map[i][j]; 
        } 
        std::cout << std::endl;
    }
    std::cout << *m_player;
}

CGame& CGame::Movement ( const char& m_movement ){
    char check = 0;

    switch ( m_movement ){
        case 'w':
            if(m_map[m_player->getPosY() - 1][m_player->getPosX()] != ' '){
                break;
            }

            m_map[m_player->getPosY()][m_player->getPosX()] = ' ';
            m_map[m_player->getPosY() - 1][m_player->getPosX()] = '^';

            m_player->movement(m_player->getPosX(),m_player->getPosY() - 1, '^');
            CGame::trapUsing( m_player->getPosX(), m_player->getPosY());

            break;
        case 's':
            if(m_map[m_player->getPosY() + 1][m_player->getPosX()] != ' '){
                break;
            }

            m_map[m_player->getPosY()][m_player->getPosX()] = ' ';
            if( m_player->getDirection() != '^' ){
                m_map[m_player->getPosY() + 1][m_player->getPosX()] = m_player->getDirection();
                m_player->movement(m_player->getPosX(), m_player->getPosY() + 1, m_player->getDirection());
                break;
            }
            m_map[m_player->getPosY() + 1][m_player->getPosX()] = '>';

            m_player->movement(m_player->getPosX(), m_player->getPosY() + 1, '>');
            CGame::trapUsing( m_player->getPosX(), m_player->getPosY());

            break;
        case 'a':
            if(m_map[m_player->getPosY()][m_player->getPosX() - 1] != ' '){
                break;
            }

            m_map[m_player->getPosY()][m_player->getPosX()] = ' ';
            m_map[m_player->getPosY()][m_player->getPosX() - 1] = '<';

            m_player->movement(m_player->getPosX() - 1, m_player->getPosY(), '<');
            CGame::trapUsing( m_player->getPosX(), m_player->getPosY());

            break;
        case 'd':
            if(m_map[m_player->getPosY()][m_player->getPosX() + 1] != ' '){
                break;
            }

            m_map[m_player->getPosY()][m_player->getPosX()] = ' ';
            m_map[m_player->getPosY()][m_player->getPosX() + 1] = '>';

            m_player->movement(m_player->getPosX() + 1, m_player->getPosY(), '>');
            CGame::trapUsing( m_player->getPosX(), m_player->getPosY());
            
            break;
        case 'q':
            this->stopGame();
            break;
        case 'e':
            if( ! this->detected( check ) ){
                break;
            }
            if( check == '$'){
                m_chest[level_flag - 1]->openChest( m_player );

                if( m_chest[level_flag - 1]->Empty() ){
                    m_map[m_chest[level_flag - 1]->getY()][m_chest[level_flag - 1]->getX()] = ' ';
                    delete m_chest[level_flag - 1];
                    m_chest[level_flag - 1] = nullptr;
                }

                break;
            }
            if( check == 'N' ){
                if( m_enemie[ level_flag - 1] ){
                    system ( "clear" );

                    char tmp_e = 0;
                    std::cout << "You can't pass, enemy is still alive !" << std::endl << "Enter something to continue" << std::endl;
                    std::cin >> tmp_e;

                    break;
                }
                CGame::saveLevel();
                m_map.clear();

                if( level_flag == progress_flag ){
                    CGame::loadNewLevel ();
                    break;
                }
                CGame::loadNextLevel();
                break;
            }
            if( check == 'V' ){
                CGame::saveLevel();
                m_map.clear();
                CGame::loadPreviousLevel();
                break;
            }
            if( m_enemie[ level_flag - 1] ){
                CCombat tmp_combat ( m_player, m_enemie[level_flag - 1] );
                if( tmp_combat.combat() ){
                    m_map[m_enemie[level_flag - 1]->getPosY()][m_enemie[level_flag - 1]->getPosX()] = ' ';
                    m_player->increaseExperience(m_enemie[level_flag - 1]->getExperience());

                    delete m_enemie[level_flag - 1];
                    m_enemie[level_flag - 1] = nullptr;

                    if( level_flag == 5 ){
                        system ("clear");

                        char if_win= 0; 
                        std::cout << "You passed all tests on Progtest, you passed this game..." << std::endl << "Enter something to continue: " << std::endl;
                        std::cin >> if_win;

                        this->stopGame();
                    }
                }
            }
            if( m_player->getHealth() <= 0 ){
                system ( "clear" );

                char if_dead = 0; 
                std::cout << "You died... " << std::endl << "Enter something to continue: " << std::endl;
                std::cin >> if_dead;

                this->stopGame();
            }
            break;
        case 'i':{
            if( ! this->detected( check ) ){
                break;
            }
            system ("clear");
            if( check == '$' ){
                m_chest[level_flag - 1]->getInfo( std::cout );
                break;
            }
            char tmp_i = 0;
            m_enemie[level_flag - 1]->printInfo(std::cout);
            std::cout << "Enter something to continue" << std::endl;
            std::cin >> tmp_i;
            break;
        }
        case 'r':
            m_player->openBackPack();
            break;
        default:
            break;
    }

    return *this;
}