/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Utentes;

/**
 *
 * @author User
 */
public class Pessoa {
    
    protected String Nome;
    protected String Morada;
    

    public String getMorada() {
            return Morada;
    
    }
    
    public void setMorada(String Morada) {
        
        this.Morada = Morada;
    }
    
    public String getNome() {
        return Nome;
        
    }
    public void setNome(String Nome) {
        this.Nome = Nome;
    }
    
public Pessoa(String n, String m) {
    
    Nome=n;
    Morada=m;
}
public Pessoa() {
    Nome="";
    Morada="";
}
    
}
