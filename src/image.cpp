#include "image/image.hpp"
#include "image/node.hpp"
#include "vector"
#include "queue"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data){
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }
    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<"0";
                }
                else{
                    std::cout<<"1";
                }
            }
            std::cout<<std::endl;
        }
    }
    Image::~Image(){
    }
    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        if (!fin.is_open()) {
        return nullptr; // Retorna nullptr si no se pudo abrir
    }
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }
    using namespace eda;
    eda::Matrix Image::getMatrix() {
    // Crear una matriz dinámica de las dimensiones de la imagen
    Matrix matriz(height, width); // Nota: ya no es un puntero

    // Recorrer cada pixel de la imagen
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Obtener el valor del pixel
            int pixelValue = getValue(i, j);
            
            // Asignar el valor a la matriz dependiendo del valor del pixel
            if (pixelValue == 1) {
                matriz.setValue(j, i, 1);
                //matriz.setValue(i, j, 1); // Setear '1' para valores que son 1 en la imagen original
            } if(pixelValue == 0){
                matriz.setValue(j, i, 0); // Setear '0' para valores que son 0
            }
        }
    }
    // Imprimir la matriz (función que ya deberías tener en la clase Matrix)
    
    int g = matriz.checkGroups();
    matriz.getGroups(g);
    
    //matriz.print();
    //matriz.printGroups(1);
    //matriz.printGroups(2);
    return matriz;

}


}
