// emei.h

int permit_recruit(object ob)
{
        object me;

        me = this_object();

        if ((string)ob->query("gender") != "Ů��")
        {
                        command("say �����ӷ��Ҷ����ɲ����е��ӡ�");
                        command("say ʩ������ѧ�գ���ȥ���֡��䵱Ͷʦ��");
                        return 0;
        }

        if (ob->query("detach/������") ||
            ob->query("betrayer/������"))
        {
                command("say �㵱���Ȼ�뿪�˶����ɣ������ֺαػ�����");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say ����ʦ����������ʦ�ţ����������Ƕ����ɲ��������ġ�");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "������")
        {
                command("say ��������ʦָ�㣬Ϊ�����������ɣ�Ī����Ҫ��ʦ���ɣ�");
                return 0;
        }

        if ((string)me->query("class") == "bonze" &&
            (string)ob->query("class") != "bonze")
        {
                command("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
                command("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�");
                return 0;
        }

        if ((int)ob->query("shen") < 0)
        {
                command("say ����������������;������������Ϊͽ��");
                return 0;
        }

        return 1;
}
