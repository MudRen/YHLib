// check recruit

int permit_recruit(object ob)
{
        if( ob->query("detach/������") || ob->query("betrayer/������") )
        {
                command("say �㵱���Ȼ�Ѿ��뿪�����ھ֣����ڸ�����Ҫ������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say �٣����ھ������������ı�������֮ͽ�϶��ǳ������⣡");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "������" &&
            ob->query("family/family_name") != "�̼ұ�" &&
            ob->query("family/master_name") != "�̽���" )
        {
                command("say ���ף����ף����Ѿ���ʦ���ˡ�");
                return 0;
        }

        return 1;
}
