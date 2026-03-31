Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'TODO: This line of code loads data into the 'LojaLivrosDataSet1.Livros' table. You can move, or remove it, as needed.
        Me.LivrosTableAdapter.Fill(Me.LojaLivrosDataSet1.Livros)

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        LivrosBindingSource1.EndEdit()
        LivrosTableAdapter.Update(LojaLivrosDataSet1)

        MessageBox.Show("Registro guardado com sucesso!")

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        LivrosBindingSource1.RemoveCurrent()

        MessageBox.Show("Registro removido com sucesso!")
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Me.Close()
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        LivrosBindingSource1.MoveNext()
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        LivrosBindingSource.MovePrevious()
    End Sub
End Class
