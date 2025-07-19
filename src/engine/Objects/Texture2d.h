//
// Created by Олег Черепанов on 18.07.2025.
//

#ifndef TEXTURE2D_H
#define TEXTURE2D_H



class Texture2d {
    public:
        unsigned int ID;
        int width, height;
        int internalFormat;
        int imageFormat;
        int Wrap_S;
        int Wrap_T;
        int Filter_Min;
        int Filter_Max;

        Texture2d();
        void Generate(int width, int height, unsigned char* data);
        void Bind() const;
};



#endif //TEXTURE2D_H
