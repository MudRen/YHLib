
int permit_recruit(object ob)
{
        if (ob->query("detach/�̼ұ�") || ob->query("betrayer/�̼ұ�"))
        {
                command("sneer");
                command("say ��������⣬�����޳�������������㣿");
                return 0;
        }

        if (ob->query("born_family") != "ɽ���̼�")
        {
                command("heng");
                command("say ���̼ұ������������ˣ������߿���");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "�̼ұ�")
        {
                command("sneer");
                command("say ���Ȼ�Ѿ���Ұ�ʦ�����ܻ���������");
                return 0;
        }

        return 1;
}

