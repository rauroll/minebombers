/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProjectileWeapon.h
 * Author: Olli
 *
 * Created on December 2, 2015, 1:55 PM
 */

#ifndef PROJECTILEWEAPON_H
#define PROJECTILEWEAPON_H

class ProjectileWeapon {
public:
    ProjectileWeapon();
    ProjectileWeapon(const ProjectileWeapon& orig);
    virtual ~ProjectileWeapon();
    
    void use(sf::Vector2u loc, sf::Vector2u dir);
    
private:

};

#endif /* PROJECTILEWEAPON_H */

