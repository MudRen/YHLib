
int permit_recruit(object ob)
{
        if (ob->query("detach/�������") || ob->query("betrayer/�������"))
        {
                command("say �㵱���Ȼ�Ѿ��뿪�˺�ľ�£����պα���Ҫ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ��������̼��ձ�һͳ�������ɲ������������ı�������֮ͽ��");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "�������")
        {
                command("say ���Ȼ�Ѿ�����ʦ�У�������������������");
                return 0;
        }

        if (ob->query("family/master_name") == "������")
        {
                command("say ��Ȼ��������ʶ�࣬����Ϊͽ�����Ӧ�úú���ϧ��");
                command("say �����������Ͻ�������ĺ�ģ��񲻹����˽�����һƬ���ģ�");
                return 0;
        }

        return 1;
}
