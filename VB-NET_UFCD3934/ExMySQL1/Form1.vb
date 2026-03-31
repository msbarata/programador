Imports System.Data.SqlClient

Public Class Form1

    Dim liga As SqlConnection = New SqlConnection("Data source=(localdb)\MSSQLLocalDB;Database=db25481;Integrated Security=True;")

    Public Sub executarQuery(query As String)

        Dim command As New SqlCommand(query, liga) 'cria um objecto SQLCommand

        liga.Open() 'Abre a ligação à BD

        command.ExecuteNonQuery() ' executar a Consulta SQL

        liga.Close() ' Fechar a ligação à BD


    End Sub


    Private Sub btnInserir_Click(sender As Object, e As EventArgs) Handles btnInserir.Click

        Dim inserirQuery As String = "INSERT INTO dados(Nome,Apelido,Idade) VALUES('" & txtNome.Text & "','" & txtApelido.Text & "', " & txtIdade.Text & ")"

        executarQuery(inserirQuery)

        MessageBox.Show("Dados inseridos com Sucesso")

    End Sub

    Private Sub btnAtualizar_Click(sender As Object, e As EventArgs) Handles btnAtualizar.Click

        Dim AtualizarQuery As String = "Update Dados Set Nome= '" & txtNome.Text & "', Apelido = '" & txtApelido.Text & "', Idade= '" & txtIdade.Text & "' WHERE Id= '" & txtCodigo.Text & "'"

        MessageBox.Show("Dados atualizados com sucesso")

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Dim adapter As New SqlDataAdapter("SELECT * from dados", liga)
        Dim table As New DataTable()

        adapter.Fill(table)

        DataGridView1.DataSource = table
    End Sub

    Private Sub DataGridView1_CellContentClick(sender As Object, e As DataGridViewCellEventArgs) Handles DataGridView1.CellContentClick

        txtNome.Text = DataGridView1.CurrentRow.Cells(5).Value
        txtApelido.Text = DataGridView1.CurrentRow.Cells(6).Value
        txtIdade.Text = DataGridView1.CurrentRow.Cells(7).Value
    End Sub
