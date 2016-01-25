#pragma once
#include <SDL/SDL_render.h>
#include <SDL/SDL_stdinc.h>
#include "types.h"
#include "Renderer.h"

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

	virtual void render(Renderer& ren,const Transform& off = Transform()) = 0;
};


class Object : public Transform , public InputObj, public UpdateObj ,public RenderObj{

public:
          
    void input() override;
    void update() override;
	void render(Renderer& ren, const Transform& off = Transform()) override;
	
private:
	void inputChildren();
    void updateChildren();
    void renderChildren(Renderer& ren, const Transform& off = Transform());
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
    
    //Shape();
};
class Point {
public:
	//vec<2, int> pos;
	void render(SDL_Renderer* ren) {
		//SDL_RenderDrawPoint(ren, pos.x, pos.y);
	}
};
class  Rect   : public Shape   {
public:
    void render(Renderer& ren,const Transform& off = Transform())  override;
    
};
class  RectLine   : public Shape   {
public:
    void render(Renderer& ren, const Transform& off = Transform())  override;
    
};

/*class Texture;
class TextureObj : RenderObj {
protected:
    SDL_Texture*  m_sdlTexture;
public:
    void render(Renderer& ren, const Transform& off = Transform()) override;
};

#include "Log.h"
#include <SDL\SDL_image.h>
#include <map>
class Texture {

	SDL_Texture*  m_sdlTexture = nullptr;
	int m_width = 0;
	int m_height = 0;
	static std::map<const std::string, Texture> m_textures;
public:
	operator SDL_Texture * () {
		return m_sdlTexture;
	}
    const int & width = m_width;
    const int & height = m_height;
	static void unloadAll() {

		auto it = m_textures.begin();
		auto end = m_textures.end();

		for (; it != end; ++it)
			it->second.unload();
		
		m_textures.clear();
	}
    

	void load(SDL_Renderer* ren, std::string path) {
		bool success = true;
		try {
			Texture & tex = m_textures.at(path);
			if (tex.m_sdlTexture)
				setTexture(tex);
			else
				success = false;
		}
		catch (const std::out_of_range ex) {
			success = false;
		}
		SDL_Surface* temp_surf = IMG_Load(path.c_str());

		if ( ! temp_surf )
			Log(std::string("\n") + SDL_GetError());
		else {
			m_sdlTexture = SDL_CreateTextureFromSurface(ren, temp_surf);
			if ( ! m_sdlTexture )
				Log(std::string("\n") + SDL_GetError());
			else
			{

			}

			SDL_FreeSurface(temp_surf);
		}
	}
	void unload() {
		SDL_DestroyTexture(m_sdlTexture);
	}
    void setTexture( const Texture & tex ) {
		
		m_sdlTexture = tex.m_sdlTexture;
		m_width = tex.width;
		m_height = tex.height;
	}
};*/
class Image        : public Object  {
private:
    SDL_Rect*  m_clipRect;
public:
    Texture    texture;
    byte       flip;
    double     rot;
    
    Image();
    void render(Renderer& ren, const Transform& off) override;
};












































