int permit_recruit(object ob)
{
        if (ob->query("detach/��ԭ���") || ob->query("betrayer/��ԭ���"))
        {
                command("heng");
                command("say �㷴���޳����Ҳ�������Ϊͽ��");
                return 0;
        }

        if (ob->query("born_family") != "��ԭ���")
        {
                command("hmm");
                command("say ����������㲻�������ˡ�");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "��ԭ���")
        {
                command("hmm");
                command("say �����������Ͷʦѧ�գ���Ӧ������Ϊ�����ܻ���������");
                return 0;
        }

        return 1;
}
