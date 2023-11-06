#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> chosen = {};

    std::string menuAll[10] = {
            "Salad",
            "Biscuits",
            "Croissant",
            "Pancake",
            "Oatmeal",
            "Cappuccino",
            "Latte",
            "Espresso",
            "Iced Tea",
            "Plain Water"
    };
    std::string menuFoodInterface[5] = {
            "1. Salad - 8.00 USD",
            "2. Biscuits - 2.50 USD",
            "3. Croissant - 3.00 USD",
            "4. Pancake - 6.00 USD",
            "5. Oatmeal - 5.00 USD"
    };
    float priceFood[5] = {
            8.0,
            2.5,
            3.0,
            6.0,
            5.0
    };
    std::string menuDrinkInterface[5] = {
            "1. Cappuccino - 3.50 USD",
            "2. Latte - 3.75 USD",
            "3. Espresso - 2.50 USD",
            "4. Iced Tea - 2.50 USD",
            "5. Plain Water - 1.00 USD"
    };
    float priceDrink[5] = {
            3.5,
            3.75,
            2.5,
            2.5,
            1.0
    };
    std::string interface[9] = {
            "1. Add a drink",
            "2. Add a food",
            "3. Check total price",
            "4. Remove a selection",
            "5. Checkout"
    };

    float sumPrice = 0.0f;
    int exit = 1;
    std::cout<<"Good morning, how may i assist you today?"<<std::endl;
    while(exit == 1){
        int n;
        for(int i = 0 ; i < sizeof(interface)/sizeof(std::string) ; i++){
            std::cout<<interface[i]<<std::endl;
        }
        std::cin>>n;
        int selection;
        switch(n){
            case 1:
                std::cout<<"Please choose a drink from the following menu by entering their assigned number:\n";
                for(int i = 0 ; i < sizeof(menuDrinkInterface)/sizeof(std::string) ; i++){
                    std::cout<<menuDrinkInterface[i]<<std::endl;
                }
                std::cin>>selection;
                sumPrice += priceDrink[selection-1];
                chosen.push_back(menuAll[selection+4]);
                std::cout<<"Process successfully done, is there anything else you'd like to do?\n";
                break;
            case 2:
                std::cout<<"Please choose a food from the following menu by entering their assigned number:\n";
                for(int i = 0 ; i < sizeof(menuFoodInterface)/sizeof(std::string) ; i++){
                    std::cout<<menuFoodInterface[i]<<std::endl;
                }
                std::cin>>selection;
                sumPrice += priceFood[selection-1];
                chosen.push_back(menuAll[selection-1]);
                std::cout<<"Process successfully done, is there anything else you'd like to do?\n";
                break;
            case 3:
                std::cout<<"Your total price would be: "<<sumPrice<<" USD\n";
                std::cout<<"Process successfully done, is there anything else you'd like to do?\n";
                break;
            case 4:
                if(chosen.size() == 0)
                {
                    std::cout<<"There is no selected items yet\n";
                    break;
                }
                for(int i = 0 ; i < chosen.size() ; i++){
                    std::cout<<i+1<<". "<<chosen[i]<<std::endl;
                }
                std::cout<<"Which item do you wish to remove?\n";
                std::cin>>selection;
                chosen.erase(chosen.begin()+(selection-1));
                std::cout<<"Process successfully done, is there anything else you'd like to do?\n";
                break;
            case 5:
                exit = 0;
                std::cout<<"Checkout completed, exiting...";
                break;
            default:
                std::cout<<"The input you have entered is undefined, please try again\n";
                break;
        }
    }
}