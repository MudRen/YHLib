int permit_recruit(object ob)
{
        if( ob->query("detach/��ɽ��") || ob->query("betrayer/��ɽ��") )
        {
                command("say �㵱�궼�Ѿ��뿪�˺�ɽ�ɣ��α���Ҫ������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���Ǻ�ɽ�����������ɣ���������ʦ֮ͽ��");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "��ɽ��" )
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬���ú�ѧϰ�������Ǻ�ɽ��������");
                return 0;
        }

        return 1;
}
