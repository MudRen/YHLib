// check recruit

int permit_recruit(object ob)
{
        if (ob->query("detach/÷ׯ") || ob->query("betrayer/÷ׯ"))
        {
                command("say �㵱���Ȼ�Ѿ��뿪��ׯ�����ںα���Ҫ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ��÷ׯ��С������Ҳ��������������ı�������֮ͽ��");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "÷ׯ" &&
            ob->query("family/family_name") != "�������" &&
            ob->query("family/master_name") != "��������")
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬��������÷ׯ���");
                return 0;
        }

        return 1;
}
