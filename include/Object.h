#pragma once
#include <SDL/SDL_render.h>
#include <SDL/SDL_stdinc.h>
#include "types.h"

class Transform{
public:
	vec2<double>  pos = 0;
	vec2<double>  size = 1;
	double        angle = 0;
};

class InputObj {

	virtual void input() = 0;
};
class UpdateObj {

	virtual void update() = 0;
};
class RenderObj {

	virtual void render(const Transform& off = Transform()) = 0;
};


class Object : public Transform , public InputObj, public UpdateObj ,public RenderObj{

public:
          
    void input() override;
    void update() override;
	void render(const Transform& off = Transform()) override;
	
private:
	void inputChildren();
    void updateChildren();
    void renderChildren(const Transform& off = Transform());
public:
    //bool hasChildren() const;
    //const std::vector<Object> & getChildren() const;
    bool hasChild(const Object& ch) const;
    void addChild(Object& ch);
    void removeChild( Object& ch);
    void removeAllChildren();
    
    bool checkColl(const Object & otherGO, vec2<double> & inters) const;

    
    
protected:
    Object*                m_parent = nullptr;
	std::vector<Object>   m_inputChildren;
	std::vector<Object>   m_updateChildren;
	std::vector<Object>   m_renderChildren;
    
};





class  Shape  : public RenderObj  {
public:
    SDL_Color      color = { 255,255,255,255 };
    
    Shape();
};
class  Rect   : public Shape   {
public:
    void render(const Transform& off = Transform())  override;
    
};
class  RectLine   : public Shape   {
public:
    void render(const Transform& off = Transform())  override;
    
};

class Texture;
class TextureObj : RenderObj {
protected:
    SDL_Texture*  m_sdlTexture;
public:
    void render(const Transform& off = Transform()) override;
};

class Texture : TextureObj {
private:
    int  m_w = 0;
    int  m_h = 0;
public:
    const int& w = m_w;
    const int& h= m_h;
    
    bool loadFromFile(cchar* filename);
    
    
    void setSdlTexture( SDL_Texture* sdlTexture, int width, int height );
              operator SDL_Texture* ();


};
class Image        : public Object  {
private:
    SDL_Rect*  m_clipRect;
public:
    Texture    texture;
    byte       flip;
    double     rot;
    
    Image();
    void render(const Transform& off) override;
};












































