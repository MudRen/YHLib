// kunlun.h

int permit_recruit(object ob)
{
        if( ob->query("detach/������") ||
            ob->query("betrayer/������") )
        {
                command("say ���㻹������������ɽ�����ҹ�����");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ�����ʹ�����������ˡ�");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "������" )
        {
                command("say ���¼�������ʦָ�㣬����������������ʲô��");
                return 0;
        }

        return 1;
}
