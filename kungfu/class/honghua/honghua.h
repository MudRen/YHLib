// honghua.h

int permit_recruit(object ob)
{
        if( ob->query("detach/�컨��") ||
            ob->query("betrayer/�컨��") )
        {
                command("say ���Ǻ컨���Ĵ�����㻹�ǵ��𣿿��㻹����������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say �ߣ����²��Ҳ��ţ����Ǻ컨��ɲ���������");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "�컨��" )
        {
                command("say ���¼�����ʦ�У��������Ǻ컨����ʲô��");
                return 0;
        }

        return 1;
}

