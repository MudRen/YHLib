int permit_recruit(object ob)
{
        command("say �Բ���������ʱ�����š�");
        return 0;

        if (ob->query("detach/������") ||
            ob->query("betrayer/������"))
        {
                command("say �㷴��������������ôһ�����");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ����治����˽����ʦ�������������֣�");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "������")
        {
                command("say ���Ѿ���ʦָ�㣬Ϊ�β��¿๦������������"
                        "�������أ�");
                return 0;
        }

        return 1;
}
