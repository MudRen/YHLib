
int permit_recruit(object ob)
{
        if (ob->query("detach/Ľ������") || ob->query("betrayer/Ľ������"))
        {
                command("sneer");
                command("say ��������⣬�����޳�������������㣿");
                return 0;
        }

        if (ob->query("born_family") != "Ľ������")
        {
                command("sneer");
                command("say �㲻������Ľ�ݼҵ��ˣ�ʦͽ�����˰ɡ�");
                return 0;
        }

        if (ob->query("family/family_name")
           && ob->query("family/family_name") != "Ľ������")
        {
                command("sneer");
                command("say ���Ȼ�Ѿ���Ұ�ʦ�����ܻ���������");
                return 0;
        }

        if (ob->query("name") == "Ľ�ݲ�"
           || ob->query("name") == "Ľ�ݸ�")
        {
                command("killair");
                command("say ���������������ʲô��˼��");
                return 0;
        }
        return 1;
}

