// duan.h

int permit_recruit(object ob)
{
        if (ob->query("detach/���ϻ���") || ob->query("betrayer/���ϻ���"))
        {
                command("say ��Ȼ�뿪�����Ƕμң��Ͳ�Ҫ������");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say �ߣ����Ǵ��������ʹ�޵ľ��ǲ��Ҳ���֮ͽ��");
                return 0;
        }

        if (ob->query("born_family") != "���ϻ���")
        {
                command("shake");
                command("say ���Ƕμ��˻�������������ˡ�");
                return 0;
        }

        if (ob->query("family/family_name")
           && ob->query("family/family_name") != "���ϻ���")
        {
                command("hmm");
                command("say �㵱���ܳ�ȥ��ʱ����ô��û���Ҫ������");
                return 0;
        }

        return 1;
}
