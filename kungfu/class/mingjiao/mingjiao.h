// honghua.h
// create by Rcwiz 2003

int permit_recruit(object ob)
{
        if( ob->query("detach/����") ||
            ob->query("betrayer/����") )
        {
                command("say �������̹̽��㻹�ǵ����㻹����������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say �ߣ����²��Ҳ��ţ��������̿ɲ���������");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "����" )
        {
                command("say ���¼�����ʦ�У���������������ʲô��");
                return 0;
        }

        return 1;
}

