Imports System.Data.SqlClient
Imports System.IO
Imports System.Drawing.Imaging

Public Class Form1

    ' DECLARAÇÃO DA CONEXÃO - ADICIONE ESTA LINHA!
    Dim liga As New SqlConnection("Data Source=desktop-5e8qc6p;Initial Catalog=Stand;Integrated Security=True")

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

        Dim insertQuery As String = "INSERT INTO Stand(Id, Marca, Modelo, Foto) VALUES (@Id, @marca, @modelo, @img)"

        Dim command As New SqlCommand(insertQuery, liga)
        command.Parameters.Add("@Id", SqlDbType.Int).Value = Convert.ToInt32(txtID.Text)
        command.Parameters.Add("@marca", SqlDbType.NVarChar).Value = TxtMarca.Text
        command.Parameters.Add("@modelo", SqlDbType.NVarChar).Value = txtModelo.Text
        command.Parameters.Add("@img", SqlDbType.Image).Value = img


        'alterar o campo Foto - com Tipo de Dados Image - senão dá erro

        ExecuteMyQuery(command, "Dados inseridos com sucesso")
        txtID.Text = ""
        TxtMarca.Text = ""
        txtModelo.Text = ""
        PictureBox2.Image = Nothing

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
        'TODO: This line of code loads data into the 'StandDataSet.Stand' table. You can move, or remove it, as needed.
        Me.StandTableAdapter.Fill(Me.StandDataSet.Stand)

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
        Dim command As New SqlCommand("Select * from Stand WHERE Id = @Id ", liga)

        command.Parameters.Add("@Id", SqlDbType.Int).Value = txtID.Text

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

End Class