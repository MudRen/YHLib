int permit_recruit(object ob)
{

        if( ob->query("detach/��ڤ��") ||
            ob->query("betrayer/��ڤ��") )
        {
                command("say �ߣ����Ȼ���˾Ͳ�Ҫ�ٻ�����");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ��Ҳ�������Ϊͽ��");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "��ڤ��" )
        {
                command("say ���������ʦָ�㣬��Ҫ���¿๦����Ҫ���Ķ��⣡");
                return 0;
        }

        return 1;
}
