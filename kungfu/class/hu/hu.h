
int permit_recruit(object ob)
{
        if( ob->query("detach/�������") || ob->query("betrayer/�������") )
        {
                command("say �㷴���޳����Ҳ�������Ϊͽ��");
                return 0;
        }

        if (ob->query("born_family") != "�������")
        {
                command("hmm");
                command("say �ҹ��������Ȼ�˶�ϡ�٣���Ҳ����������֮�ˡ�");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "�������")
        {
                command("hmm");
                command("say ���Ȼ�Ѿ���Ұ�ʦ����Ӧ������Ϊ�����ܻ���������");
                return 0;
        }

        return 1;
}

