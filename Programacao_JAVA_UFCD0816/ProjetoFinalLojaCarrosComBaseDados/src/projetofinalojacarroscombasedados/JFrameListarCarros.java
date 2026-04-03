package projetofinalojacarroscombasedados;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.sql.ResultSet;

public class JFrameListarCarros extends javax.swing.JFrame {

    /**
     * Creates new form JFrameListarDonos
     */
    public JFrameListarCarros() {
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

   ResultSet resultadoQuery = stat1.executeQuery("SELECT m.nome_modelo, c.cor, m.motor, c.ano_fabricacao, p.valor " +
    "FROM lojacarros.carro c " + "LEFT JOIN lojacarros.modelo m ON c.id_modelo = m.id_modelo " + "LEFT JOIN lojacarros.preco p ON c.id_preco = p.id_preco");
  
      //Mysql

   //ResultSet resultadoQuery = stat1.executeQuery("Select * From utentes.dadosutentes");
  String texto = "";
   
  texto = String.format("%-20s %-20s %-35s %-10s %-15s%n", "Nome", "Cor", "Motor", "Ano", "Preço");
  texto += "---------------------------------------------------------------------------------------------------\n";
   
   while(resultadoQuery.next()) 
          texto+= String.format("%-20s %-20s %-35s %-10s %10.2f%n",
                resultadoQuery.getString("nome_modelo"),
                resultadoQuery.getString("cor"),
                resultadoQuery.getString("motor"),
                resultadoQuery.getString("ano_fabricacao"),
                resultadoQuery.getDouble("valor")); 
                     
   jTextArea1.setFont(new java.awt.Font("Monospaced", 0, 12));
   jTextArea1.setText(texto);
   
   
    }

     catch (Exception Ex)

            {

            System.out.println("Xampp Server - problema:"+Ex);

            }  
         
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(153, 153, 255));

        jLabel1.setFont(new java.awt.Font("Segoe UI", 1, 18)); // NOI18N
        jLabel1.setText("Conheça nosso Estoque de Carros");

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(17, 17, 17)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 756, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(241, 241, 241)
                        .addComponent(jLabel1)))
                .addContainerGap(21, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 251, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(20, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
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
            java.util.logging.Logger.getLogger(JFrameListarCarros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JFrameListarCarros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JFrameListarCarros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JFrameListarCarros.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JFrameListarCarros().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
}
