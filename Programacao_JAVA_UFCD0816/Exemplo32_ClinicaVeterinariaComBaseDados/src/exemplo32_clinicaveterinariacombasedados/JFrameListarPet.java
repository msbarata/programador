
package exemplo32_clinicaveterinariacombasedados;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.sql.ResultSet;

public class JFrameListarPet extends javax.swing.JFrame {

    /**
     * Creates new form JFrameListarPet
     */
    public JFrameListarPet() {
        initComponents();
        
        actualiza();
    }

    void actualiza(){
   
     try {
              //SQL Server

    //Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");

    //Connection SQlCnn = DriverManager.getConnection("jdbc:sqlserver://localhost\\SQLEXPRESS:52836;user=java; password=java");

    //XAMPP

    Connection SQlCnn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/?user=root");  

    //Mysql

    //Connection SQlCnn = DriverManager.getConnection("jdbc:mysql://localhost:3306/","root","123456");  

    System.out.print("Ligação com sucesso");
    Statement stat1= SQlCnn.createStatement();
        
    
       //SQL Server

   //ResultSet resultadoQuery = stat1.executeQuery("Select * From utentes.dbo.dadosutentes");

   //XAMPP

   ResultSet resultadoQuery = stat1.executeQuery("Select * From clinicaveterinaria.pet");

   //Mysql

   //ResultSet resultadoQuery = stat1.executeQuery("Select * From utentes.dadosutentes");
 
   
   String texto="";
   while(resultadoQuery.next()) 
          texto= texto + resultadoQuery.getString("ID")
                + "\t" + resultadoQuery.getString("Nome")
                + "\t" + resultadoQuery.getString("Raca")
                + "\t" + resultadoQuery.getString("Dono")                  
                       +"\n";
   jTextArea1.setText(texto);       
     //texto=texto.replaceAll("null","  ");
   SQlCnn.close();
   
   }

     catch (Exception Ex)

            {

            System.out.println("Base Server com problema:"+Ex);

            }  
         
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jLabel1.setText("Listar Pets");

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(164, 164, 164)
                .addComponent(jLabel1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 388, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 254, Short.MAX_VALUE)
                .addGap(12, 12, 12))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(JFrameListarPet.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JFrameListarPet.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JFrameListarPet.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JFrameListarPet.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JFrameListarPet().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
}
