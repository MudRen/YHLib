int permit_recruit(object ob)
{
        if( ob->query("detach/�����") || ob->query("betrayer/�����") )
        {
                command("say �㵱�궼�Ѿ��뿪�˾���ȣ��α���Ҫ������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���Ǿ�������������ɣ���������ʦ֮ͽ��");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "�����" )
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬���ú�ѧϰ�������Ǿ����������");
                return 0;
        }

        return 1;
}
