// check recruit

int permit_recruit(object ob)
{
        if (ob->query("detach/������") || ob->query("betrayer/������"))
        {
                command("say �㵱���Ȼ�Ѿ��뿪�����ǣ����ںα���Ҫ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ����ѩɽ��������ݾ����������ı�������֮ͽ��");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "������" &&
            ob->query("family/family_name") != "����ׯ" &&
            ob->query("family/master_name") != "ʯ��")
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬��������ѩɽ���ɸ��");
                return 0;
        }

        return 1;
}
