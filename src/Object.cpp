//#include <algorithm>
#include "../include/Object.h"
#include "sdlRenderer.h"







void Object:: input()   {
	inputChildren();
}
void Object:: update()  {
	updateChildren();
}
void Object::render(const Transform& off)  {

	Transform newTrans;

	newTrans.pos = off.pos + (this->pos * off.size);
	newTrans.size = this->size * off.size;
	newTrans.angle = this->angle + off.angle;

	// render this

	renderChildren(newTrans);
}




/*bool Object::    hasChildren ()               const  {
    
	return ! m_children.empty();
}*/
/*const std::vector<Object> & Object::  getChildren() const  {
    
    return m_children;
}*/
bool Object::       hasChild (const Object& ch) const  {

	{
		auto itEnd = m_inputChildren.end();
		for (auto it = m_inputChildren.begin(); it != itEnd; ++it) {
			if (&ch == &(*it))
				return true;
		}
	}
	{
		auto itEnd = m_updateChildren.end();

		for (auto it = m_updateChildren.begin(); it != itEnd; ++it) {

			if (&ch == &(*it))
				return true;
		}
	}
	{
		auto itEnd = m_renderChildren.end();

		for (auto it = m_renderChildren.begin(); it != itEnd; ++it) {

			if (&ch == &(*it))
				return true;
		}
	}
	return false;
}
void Object::  inputChildren ()                 {

	auto itEnd = m_inputChildren.end();
    for (auto it = m_inputChildren.begin(); it != itEnd; ++it)
        (*it).input();
}
void Object:: updateChildren ()                 {
    
	auto itEnd = m_updateChildren.end();
    for (auto it = m_updateChildren.begin(); it != itEnd; ++it)
        (*it).update();
}
void Object::renderChildren(const Transform& off)  {

	auto itEnd = m_renderChildren.end();
	for (auto it = m_renderChildren.begin(); it != itEnd; ++it)
		(*it).render(off);
}

void Object::    addChild (Object& ch)  {
    
    if ( ! hasChild(ch) )  {
		m_inputChildren.push_back(ch);
		m_updateChildren.push_back(ch);
		m_renderChildren.push_back(ch);
    }
    
}
/*void Object:: removeChild (Object& ch)  {
    
	auto itEnd = m_children.end();
	for (auto it = m_children.begin(); it != itEnd; ++it) {
        
		if ( &ch == &(*it) ) {

			m_children.erase(it);
			ch.removeParent();
		}
    }

}*/
void Object:: removeAllChildren ()  {

	m_inputChildren.clear();
	m_updateChildren.clear();
	m_renderChildren.clear();
}

bool Object:: checkColl (const Object & otherGO, vec2<double> & inters) const  {
    
    double thisRight  = pos.x + size.x;
    double thisBottom = pos.y + size.y;
    
    double otherRight  = otherGO.pos.x + otherGO.size.x;
    double otherBottom = otherGO.pos.y + otherGO.size.y;
    
    if ( (pos.x < otherRight  && thisRight >  otherGO.pos.x)
      && (pos.y < otherBottom && thisBottom > otherGO.pos.y) )  {
        
        
        double Amin, Amax, Bmin, Bmax;
        
        /* Horizontal intersection */
        Amin = pos.x;
        Amax = Amin + size.x;
        Bmin = otherGO.pos.x;
        Bmax = Bmin + otherGO.size.x;
        if (Bmin > Amin)
            Amin = Bmin;
        if (Bmax < Amax)
            Amax = Bmax;
        inters.x = Amax - Amin;
        
        /* Vertical intersection */
        Amin = pos.y;
        Amax = Amin + size.y;
        Bmin = otherGO.pos.y;
        Bmax = Bmin + otherGO.size.y;
        if (Bmin > Amin)
            Amin = Bmin;
        if (Bmax < Amax)
            Amax = Bmax;
        inters.y = Amax - Amin;
        
        return true;
    }
    else
        return false;
}



















void Rect::render(const Transform& off)  {
    
    SDL_Rect rect = {};
    rect.x = static_cast<int>( off.pos.x );
    rect.y = static_cast<int>( off.pos.y );
    rect.w = static_cast<int>(off.size.x );
    rect.h = static_cast<int>(off.size.y );
    
    SDL_SetRenderDrawColor(sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(sdlRenderer, &rect);
}






void RectLine::render(const Transform& off)  {
    
	SDL_Rect rect = {
	static_cast<int>(off.pos.x),
	static_cast<int>(off.pos.y),
	static_cast<int>(off.size.x),
	static_cast<int>(off.size.y)
	};
    
    SDL_SetRenderDrawColor(sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(sdlRenderer, &rect);
}





void TextureObj::render(const Transform& off) {
    
    SDL_Rect toRect;
    
    toRect.x  = (int)off.pos.x;
    toRect.y  = (int)off.pos.y;
    toRect.w  = (int)off.size.x;
    toRect.h  = (int)off.size.y;
    
    SDL_RenderCopyEx( sdlRenderer, m_sdlTexture, NULL, &toRect, off.angle, NULL, SDL_FLIP_NONE);//(SDL_RendererFlip)flip );
}


void Texture:: setSdlTexture( SDL_Texture* sdlTexture, int width, int height )  {
    
    m_sdlTexture = sdlTexture;
    
    m_w  = width;
    m_h  = height;
}
         Texture::  operator SDL_Texture* () {
    
    return m_sdlTexture;
}








Image::  Image () :
    Object (),
    m_clipRect (NULL),
       texture (),
          flip (0),
           rot (0.)
{}

void Image::render(const Transform& off) {
    
    SDL_Rect toRect;
    
    toRect.x  = (int)pos.x;
	toRect.y  = (int)pos.y;
    toRect.w  = int( size.x * (float)texture.w );
    toRect.h  = int( size.y * (float)texture.h );
    
    //SDL_RenderCopyEx( sdlRenderer, texture, m_clipRect, &toRect, rot, NULL, (SDL_RendererFlip)flip );
}
























