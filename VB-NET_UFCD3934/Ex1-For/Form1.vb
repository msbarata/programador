Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim numero1 As Integer
        Dim numero2 As Integer
        Dim multiplicador As Integer
        Dim resultado As Integer
        Dim i As Integer

        numero1 = Val(TextBox1.Text)
        numero2 = Val(TextBox2.Text)

        multiplicador = ComboBox1.Text

        ListBox1.Items.Clear()
        For i = numero1 To numero2
            resultado = i * multiplicador
            ListBox1.Items.Add(i & " X " & multiplicador & " = " & resultado)
        Next


    End Sub

    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        For Each info As TimeZoneInfo In TimeZoneInfo.GetSystemTimeZones
            ListBox2.Items.Add(info)
        Next
    End Sub
End Class
