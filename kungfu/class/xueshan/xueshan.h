// check recruit

int permit_recruit(object ob)
{
        if (ob->query("detach/������") || ob->query("betrayer/������"))
        {
                command("say ���Ȼ�Ѿ��뿪�˴����£����ܻ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ���Ǵ����������ʦ֮ͽ���㻹�������");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "������")
        {
                command("say ����ʦ��ָ�㣬��ѭ�򽥽�������óȻ��ʦ��");
                return 0;
        }

        return 1;
}
