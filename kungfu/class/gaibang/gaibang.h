
int permit_recruit(object ob)
{
        if (ob->query("detach/ؤ��") || ob->query("betrayer/ؤ��"))
        {
                command("say �ٺ٣��㵱���ߵ�ʱ������ô˵�ģ�");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ����ؤ��������������������������ʦ֮ͽ��");
                return 0;
        }

        if (ob->query("family/family_name")
           && ob->query("family/family_name") != "ؤ��")
        {
                command("say ���Ȼ�Ѿ�������ʦָ�㣬��������ؤ���ʲô��");
                return 0;
        }
        return 1;
}
