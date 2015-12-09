#pragma once
#include <iostream>
#include <SDL/SDL_render.h>
#include <SDL/SDL_stdinc.h>
#include "types.h"




class Object  {

public:
    vec2<double>  pos;
    vec2<double>  size;
    
    
    
    Object();
    
    virtual void input();
    virtual void update();
    virtual void render();
    
    void inputChildren()  const;
    void updateChildren() const;
    void renderChildren() const;
    
    bool hasParent() const;
    Object* getParent() const;
    void addParent(Object* newParent);
    void removeParent();
    
    bool hasChildren() const;
    std::vector<Object*> * getChildren() const;
    bool hasChild(Object* ch) const;
    void addChild(Object* ch);
    void removeChild(Object* ch);
    void removeAllChildren();
    
    bool checkColl(const Object & otherGO, vec2<double> & inters) const;

    
    
protected:
    Object*                m_parent;
    std::vector<Object*> * m_children;
    
};



class Color  {
private:
    Uint32 m_color;
public:
    Uint8& r;
    Uint8& g;
    Uint8& b;
    Uint8& a;
    
    Color();
    Color(const Uint32& newColor);
           operator Uint32    () const;
    Color& operator =         (const Color& newColor);
    Color& operator =         (const Uint32& newColor);
};


class  Shape  : public Object  {
public:
    Color      color;
    
    Shape();
};
class  Rect   : public Shape   {
public:
    void render() override;
    
};
class  RectLine   : public Shape   {
public:
    void render() override;
    
};


class Texture  {
public:
    const int& w;
    const int& h;
    
    Texture();
    Texture( SDL_Texture* sdlTexture, int width, int height );
    
    void setSdlTexture( SDL_Texture* sdlTexture, int width, int height );
    
              operator SDL_Texture* ();
    Texture&  operator =            (const Texture& tex);

private:
    SDL_Texture*  m_sdlTexture;
    
    int  m_w;
    int  m_h;
};
class Image        : public Object  {
private:
    SDL_Rect*  m_clipRect;
public:
    Texture    texture;
    byte       flip;
    double     rot;
    
    Image();
    void render() override;
};












































