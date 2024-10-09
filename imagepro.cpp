#include "image/image.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main(int nargs, char** vargs) {
    std::string respuesta;
    image::Image* im[100]; // Mover la declaración aquí

    std::cout << "Bienvenido a ImagePro" << std::endl;
    std::string imagesNames[100]= {};
    std::string fileNames[100]= {};
    while (true) {
        std::cout << "> "; // Indicar que se espera un comando
        std::string linea;
        std::string words[100]; // Define un tamaño máximo para el array
        int count = 0;

        std::cout << "Ingresa una linea: ";
        std::getline(std::cin, linea);
        std::istringstream stream(linea);
        std::string word;
         

        while (stream >> word && count < 100) {
        words[count] = word;
        count++;
    }
        // Si hay un espacio, extrae la primera word, si no, toma toda la línea
        if (words[0] == "exit") {
            return 0; // Salir del programa


        } else if (words[2] == "read") {
            int i= 0;
            while(imagesNames[i] != ""){
                i++;
            }
            imagesNames[i] = words[0];
            fileNames[i] = words[3];
           //std::string filename("images/image_1.bmp");
            std::cout << "Cargando imagen desde: " << fileNames[i]<< std::endl;
            im[i] = image::Image::readImage(fileNames[i]); // Cargar la imagen
            if (im[i]) {
                std::cout << "Imagen cargada exitosamente." << std::endl;
            } else {
                std::cout << "Error al cargar la imagen." << std::endl;
            }}

        else if (words[0] == "show") {
            int j= 0;
            while(imagesNames[j] != words[1]){
                j++;
            }
            if (im[j]) { // Verificar que la imagen se haya cargado
                im[j]->show(); // Mostrar la imagen
            } else {
                std::cout << "No hay imagen cargada. Usa 'read' para cargar una imagen." << std::endl;
            }}
        else if (words[0] == "ShowRegion") {
            int g = 0;
            while(imagesNames[g] != words[1]){
                g++;       
            }
            eda::Matrix matriz = im[g]->getMatrix();
            int num = std::stoi(words[2]);
            matriz.printGroups(num);}

        else if ((words[0] == "getRegions")) {
        int k = 0;
            while(imagesNames[k] != words[1]){
                k++;
            }
        // Verificar que im[1] esté inicializado antes de llamar a getRegions
        if (im[k] != nullptr) {
        eda::Matrix matriz = im[k]->getMatrix();
        // Aquí podrías hacer algo con 'matriz', como imprimirla o procesarla
        } else {
            std::cout << "No hay imagen cargada en la posición o no se especifico grupo a imprimir." << std::endl;
        }
        }
        else {
            std::cout << "Respuesta invalida" << std::endl;
            std::cout << "Respuestas permitidas: \n-> <Nombre_sin_Espacios> = read <Path> \n-> Show <Nombre> \n-> ShowRegion <Nombre> <Grupo>\n-> getRegions <Nombre> \n-> exit " << std::endl;
        }
    }
    
    for(int i = 0; i < 100; i++) {
    delete im[i]; // Limpiar la imagen antes de salir (si es necesario)
}
    return 0;
}
