// yaowang.h

int permit_recruit(object ob)
{
        if( ob->query("detach/ҩ����") ||
            ob->query("betrayer/ҩ����") )
        {
                command("say ���Ȼ�Ѿ��뿪��ҩ���ȣ�������Ҫ������");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ�����ҩ������С����ȴ������ʦ֮ͽ��");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "ҩ����" )
        {
                command("say ���������ʦָ�㣬��Ҫ���¿๦����Ҫ���Ķ��⣡");
                return 0;
        }

        return 1;
}
