
int permit_recruit(object ob)
{
        if (ob->query("detach/���չ�") ||
            ob->query("betrayer/���չ�"))
        {
                command("say ���Ȼ�Ѿ��������������ҿɲ�������������");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") == "���չ�")
        {
                command("say ���Ȼ�Ѿ�Ͷ�����������£�����Ȼ������������֪���书��");
                command("say ������Ҫ����ֱ��������ѧ���ˣ�����������ʦ֮��");
                return 0;
        }

        if (ob->query("family/family_name"))
        {
                command("say �����ʦ��ȥ�������������¡�");
                return 0;
        }

        return 1;
}
