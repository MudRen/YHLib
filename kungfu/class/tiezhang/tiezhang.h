// check recruit

int permit_recruit(object ob)
{
        if( ob->query("detach/���ư�") || ob->query("betrayer/���ư�") )
        {
                command("say �㵱���Ȼ�Ѿ��뿪������ڸ�����Ҫ������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say �����ư���Ȼ�����������ɣ������������ı�������֮ͽ���ǲ���Ҫ�ģ�");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "���ư�" &&
            ob->query("family/family_name") != "�����" &&
            ob->query("family/master_name") != "��ǧ��" )
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬�����������ư���");
                return 0;
        }

        return 1;
}
