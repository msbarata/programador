/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Utentes;

import java.util.ArrayList;

/**
 *
 * @author User
 */
public class Utente extends Pessoa {
    
    public static ArrayList<Utente> listaUtentes=new ArrayList<Utente>();
    
    private double NISS;
    
        public double getNISS() {
            return NISS;
        }
        
     public void setNISS(int NIF) {
         this.NISS = NISS;
      }
    
    public Utente(double NISS, String Nome, String Morada)  {
        
       this.NISS = NISS;
       this.Nome=Nome;
       this.Morada=Morada;
    }
      
    
}
