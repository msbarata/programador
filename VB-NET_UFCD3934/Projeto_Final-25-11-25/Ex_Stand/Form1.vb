Imports System.Data.SqlClient
Imports System.IO
Imports System.Drawing.Imaging

Public Class Form1




    Public Sub ExecuteMyQuery(MyCommand As SqlCommand, MyMessage As String)

        liga.Open()

        If MyCommand.ExecuteNonQuery = 1 Then

            MessageBox.Show(MyMessage)

        Else
            MessageBox.Show("Dados não inseridos")


        End If

        liga.Close()


        populateDatagridview("")

    End Sub

    Private Sub btnInserir_Click(sender As Object, e As EventArgs) Handles btnInserir.Click

        Dim ms As New MemoryStream
        PictureBox2.Image.Save(ms, PictureBox2.Image.RawFormat)
        Dim img() As Byte
        img = ms.ToArray()

        Dim insertQuery As String = "Insert INTO Stand(Marca,Modelo,Foto)Values ('" & TxtMarca.Text & "','" & txtModelo.Text & "', @img)"

        Dim command As New SqlCommand(insertQuery, liga)
        command.Parameters.Add("@img", SqlDbType.Image).Value = img

        'alterar o campo Foto - com Tipo de Dados Image - senão dá erro

        ExecuteMyQuery(command, "Dados inseridos com sucesso")
        TxtMarca.Text = ""
        txtModelo.Text = ""

    End Sub

    Private Sub BtnUpload_Click(sender As Object, e As EventArgs) Handles BtnUpload.Click
        Dim opf As New OpenFileDialog

        opf.Filter = "Choose Image(*.JPG,*.PNG,*.GIF)|*.jpg;*.png;*.gif"

        If opf.ShowDialog = Windows.Forms.DialogResult.OK Then
            PictureBox2.Image = Image.FromFile(opf.FileName)
        End If

        Dim ms As New MemoryStream
        PictureBox2.Image.Save(ms, PictureBox2.Image.RawFormat)
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'TODO: This line of code loads data into the 'StandDataSet.Autos' table. You can move, or remove it, as needed.
        Me.AutosTableAdapter.Fill(Me.StandDataSet.Autos)
        Dim command As New SqlCommand("Select * from Stand", liga)
        Dim adapter As New SqlDataAdapter(command)
        Dim table As New DataTable()
        adapter.Fill(table)


        DataGridView1.AllowUserToAddRows = False


        DataGridView1.RowTemplate.Height = 100
        Dim imgc As New DataGridViewImageColumn
        DataGridView1.DataSource = table


        'imgc = DataGridView1.Columns(3)
        imgc.ImageLayout = DataGridViewImageCellLayout.Stretch

    End Sub

    Private Sub btnPesquisa_Click(sender As Object, e As EventArgs) Handles btnPesquisa.Click
        Dim command As New SqlCommand("Select * from Stand WHERE id = @id ", liga)


        command.Parameters.Add("@id", SqlDbType.Int).Value = txtID.Text


        Dim adapter As New SqlDataAdapter(command)


        Dim table As New DataTable()


        adapter.Fill(table)


        If table.Rows.Count() <= 0 Then


            MessageBox.Show("Sem registos")


        Else


            txtID.Text = table.Rows(0)(0).ToString()
            TxtMarca.Text = table.Rows(0)(1).ToString()
            txtModelo.Text = table.Rows(0)(2).ToString()


            Dim img() As Byte


            img = table.Rows(0)(3)


            Dim ms As New MemoryStream(img)


            PictureBox2.Image = Image.FromStream(ms)


        End If

    End Sub

    Private Sub DataGridView1_Click(sender As Object, e As DataGridViewCellEventArgs) Handles DataGridView1.CellContentClick
        Dim img As Byte()
        img = DataGridView1.CurrentRow.Cells(3).Value
        Dim ms As New MemoryStream(img)
        PictureBox2.Image = Image.FromStream(ms)


        txtID.Text = DataGridView1.CurrentRow.Cells(0).Value
        TxtMarca.Text = DataGridView1.CurrentRow.Cells(1).Value
        txtModelo.Text = DataGridView1.CurrentRow.Cells(2).Value


    End Sub

    Private Sub btnActualizar_Click(sender As Object, e As EventArgs) Handles btnActualizar.Click
        Dim ms As New MemoryStream
        PictureBox2.Image.Save(ms, PictureBox2.Image.RawFormat)
        Dim img() As Byte
        img = ms.ToArray()
        Dim updateQuery As String = "UPDATE Stand SET Marca = '" & TxtMarca.Text & "',Modelo = '" & txtModelo.Text & "',Foto = @img WHERE id = " & txtID.Text


        Dim command As New SqlCommand(updateQuery, liga)
        command.Parameters.Add("@img", SqlDbType.Image).Value = img


        ExecuteMyQuery(command, " Dados Actualizados ")

    End Sub

    Private Sub btnEliminar_Click(sender As Object, e As EventArgs) Handles btnEliminar.Click
        Dim deleteQuery As String = "DELETE FROM Stand WHERE id = " & txtID.Text


        Dim command As New SqlCommand(deleteQuery, liga)


        ExecuteMyQuery(command, " Dados eliminados ")



    End Sub
    Public Sub populateDatagridview(valueToSearch As String)


        Dim searchQuery As String = "SELECT * From stand WHERE CONCAT(Marca,Modelo) like '%" & valueToSearch & "%'"


        Dim command As New SqlCommand(searchQuery, liga)
        Dim adapter As New SqlDataAdapter(command)
        Dim table As New DataTable()
        adapter.Fill(table)


        DataGridView1.AllowUserToAddRows = False


        DataGridView1.RowTemplate.Height = 100
        Dim imgc As New DataGridViewImageColumn
        DataGridView1.DataSource = table


        imgc = DataGridView1.Columns(3)
        imgc.ImageLayout = DataGridViewImageCellLayout.Normal


    End Sub

    Private Sub txtPesquisa_TextChanged(sender As Object, e As EventArgs)
        populateDatagridview(txtPesquisa.Text)
    End Sub
End Class
