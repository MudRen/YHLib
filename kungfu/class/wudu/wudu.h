// wudu.h

int permit_recruit(object ob)
{
        if (ob->query("detach/�嶾��") || ob->query("betrayer/�嶾��"))
        {
                command("say ���Ȼ�Ѿ���̣��ͱ��ٻ�����");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ��ʦ֮ͽ���ߣ�С���Ұ���ǧ����У�");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "�嶾��")
        {
                command("say �㲻���Ѿ�����ʦ��ô��������ʲô�����Ե�ô��");
                return 0;
        }

        if (ob->query("family/master_name") == "������")
        {
                command("sneer");
                command("say ��Ȼ���Ѿ��������Ǹ����ˣ�ȴ��������������");
                return 0;
        }

        return 1;
}
