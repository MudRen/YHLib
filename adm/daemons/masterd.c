// masterd.c 
// Written by Vin for Heros.cn 2002/07/13.

#include <ansi.h>
inherit F_DBASE;

// �����ṩ���ⲿ���õĽӿں���
public mixed teach_pfm(object who, object ob, mapping b);
public mixed give_item(object who, object ob, mapping b);

// ��Ӧ��������� skills �Ŀɼ�������
string *valid_types = ({
        "force",
        "dodge",
        "unarmed",
        "cuff",
        "strike",
        "finger",
        "hand",
        "claw",
        "sword",
        "blade",
        "staff",
        "hammer",
        "club",
        "whip",
        "dagger",
        "throwing",
        "parry",
        "magic",
        "medical",
        "poison",
        "chuixiao-jifa",
        "tanqin-jifa",
        "guzheng-jifa",
        "cooking",
});

// �����书����
public mixed teach_pfm(object who, object ob, mapping b)
{
        string name, perform;           // �������Ƽ����н��̼�¼
        int i;                          // ������Ҫ����������ѭ����
        string msg;                     // ����ĳЩ������Ϣ������
        string msg1, msg2;              // ��ʾ������Ϣ���ش���Ϣ
        string sk1, sk2, sk3, sk4, sk5; // ����Ҫ���书����
        int lv1, lv2, lv3, lv4, lv5;    // ����Ӧ���书�ȼ�
        int free;                       // ���������������Ӧ��������øò�������
                                        // ���뿼�Ǵ������뱻�����ߵ������Ƿ�һ��
        string family;                  // �����ߵ����ɣ���������ù�����������Ҫ
                                        // ����˫��������Ϊͬһ����
        int gongxian, shen;             // ����Ĺ��׼���
        int force, dodge;               // ������ڹ��ȼ����Ṧ�ȼ�
        int neili, jingli;              // �������������������
        string temp1, temp2, temp3;     // Ҫ��Ľ��̼�¼
        string tmsg1, tmsg2, tmsg3;     // Ҫ��Ľ��̼�¼�Ļش���Ϣ

        // ���û��ָ�������򷵻�
        if (! stringp(name = b["name"])
           || ! stringp(perform = b["perform"]))
                return 0;

        // �ж��������ɣ���Ϊ�������ڣ�Ӧ��� free ����
        if (! intp(free = b["free"]) || free <= 0)
        {
                family = ob->query("family/family_name");

                if (who->query("family/family_name") != family)
                        return RANK_D->query_respect(who) + "����" +
                               family + "����ԨԴ����֪�˻��Ӻ�˵��";
        }

        // ����Ѿ�ѧ�ᣬ�򷵻�
        if (who->query(perform))
        {
                switch (random(4))
                {
                case 0 :
                        msg = "�Լ���ȥ������������ʲô��";
                        break;

                case 1 :
                        msg = "�Ҳ����Ѿ��̹�����ô���Լ���ȥ����";
                        break;

                case 2 :
                        msg = "���̵ܽĶ��̸����ˣ�ʣ�µ����Լ�����ɡ�";
                        break;

                default :
                        msg = "�����㲻���Ѿ�����ô����������������";
                        break;
                }
                return msg;
        }

        // �ж���������Ҫ��
        if (intp(shen = b["shen"]))
        {
                // ���Ҫ��Ϊ���������������ж�
                if (shen < 0 && who->query("shen") > shen)
                        return "�ߣ������������Ĵ�����֮������"
                               "�ܸɳ�ʲô���£�";

                // ���Ҫ��Ϊ����������С���ж�
                if (shen > 0 && who->query("shen") < shen)
                        return "��Ŀǰ�������������²���������"
                               "��ʱ�����ܴ��㡣";
        }

        // �ж����ɹ��׵�Ҫ��
        if (intp(gongxian = b["gongxian"])
           && who->query("gongxian") < gongxian)
                return "��Ϊ" + who->query("family/family_name") +
                       "�����Ĺ��ײ�����������ʱ�����ܴ��㡣";

        // �ж��ض��Ľ��̼�¼Ҫ��
        if (stringp(temp1 = b["temp1"]) && ! who->query(temp1))
        {
                if (stringp(tmsg1 = b["tmsg1"]))
                        return tmsg1;
                else
                        return "����ĳЩ��Եδ������������ʱ��"
                               "���ܴ����㡣";
        }

        if (stringp(temp2 = b["temp2"]) && ! who->query(temp2))
        {
                if (stringp(tmsg2 = b["tmsg2"]))
                        return tmsg2;
                else
                        return "����ĳЩ��Եδ������������ʱ��"
                               "���ܴ����㡣";
        }

        if (stringp(temp3 = b["temp3"]) && ! who->query(temp3))
        {
                if (stringp(tmsg3 = b["tmsg3"]))
                        return tmsg3;
                else
                        return "����ĳЩ��Եδ������������ʱ��"
                               "���ܴ����㡣";
        }

        // �ж��ض����书�������� sk1 ӦΪ�� skills 
        if (stringp(sk1 = b["sk1"]) && intp(lv1 = b["lv1"]))
        {
                if (who->query_skill(sk1, 1) <= 0)
                        return "����" + to_chinese(sk1) + "��"
                               "δ��ѧ������̸���п��ԣ�";

                if (who->query_skill(sk1, 1) < lv1)
                        return "���" + to_chinese(sk1) + "��"
                               "�˽⻹�����������޷�������С�";
        }

        if (stringp(sk2 = b["sk2"]) && intp(lv2 = b["lv2"])
           && who->query_skill(sk2, 1) < lv2)
                return "���" + to_chinese(sk2) + "���˽⻹��"
                       "���������޷�������С�";

        if (stringp(sk3 = b["sk3"]) && intp(lv3 = b["lv3"])
           && who->query_skill(sk3, 1) < lv3)
                return "���" + to_chinese(sk3) + "���˽⻹��"
                       "���������޷�������С�";

        if (stringp(sk4 = b["sk4"]) && intp(lv4 = b["lv4"])
           && who->query_skill(sk4, 1) < lv4)
                return "���" + to_chinese(sk4) + "���˽⻹��"
                       "���������޷�������С�";

        if (stringp(sk5 = b["sk5"]) && intp(lv5 = b["lv5"])
           && who->query_skill(sk5, 1) < lv5)
                return "���" + to_chinese(sk5) + "���˽⻹��"
                       "���������޷�������С�";

        // �жϾ��ж��ڹ���Ҫ��
        if (intp(force = b["force"])
           && force > 0
           && who->query_skill("force") < force)
                return "��Ŀǰ���ڹ�����㣬��ȥ���������ɡ�";

        // �жϾ��ж��Ṧ��Ҫ��
        if (intp(dodge = b["dodge"])
           && dodge > 0
           && who->query_skill("dodge") < dodge)
                return "��Ŀǰ���Ṧ����㣬��ȥ���������ɡ�";

        // �жϾ��ж��������޵�Ҫ��
        if (intp(neili = b["neili"])
           && neili > 0
           && who->query("max_neili") < neili)
                return "�����ڵ�������Ϊ���㣬�����ߵ������ɡ�";

        // �жϾ��жԾ������޵�Ҫ��
        if (intp(jingli = b["jingli"])
           && jingli > 0
           && who->query("max_jingli") < jingli)
                return "�����ڵľ�����Ϊ���㣬�����ߵ������ɡ�";

        // ����ѧϰ���е�������Ϣ
        if (stringp(msg1 = b["msg1"]))
        {
                msg = msg1;
        } else
        {
                switch (random(4))
                {
                case 0 :
                        msg = "$N΢΢���˵�ͷ�����ֽ�$n" HIY "��"
                              "����ǰ��������$n" HIY "���Ͻ�����"
                              "���죬����ʱ���ֱȻ���ʾ��ʲô����"
                              "��ȫ��" + to_chinese(sk1) + "�ľ�"
                              "΢Ҫ�衣$n" HIY "�������һЦ����"
                              "����$N�Ľ̵���������";
                        break;

                case 1 :
                        msg = "$N������$n" HIY "��ã�����΢΢��"
                              "�˵�ͷ��˵�������Ҹ�����ʾһ�飬��"
                              "������ˡ���$N�������䣬�漴�����"
                              "���������ƣ���������ʾ��" +
                              to_chinese(sk1) + "����ʽ��$n" HIY
                              "ֻ��$N��ʽ���棬����Ƿ���ʵ��ǰ��"
                              "δ�ţ���ʱ���и���";
                        break;

                case 2 :
                        msg = "$N���˿�$n" HIY "����Ϊ�����˵��"
                              "�����벻�����" + to_chinese(sk1) +
                              "��չ������٣��Ѵ�˰㾳�硣���ף�"
                              "���ס������ұ㴫�����У��ɼ������"
                              "����˵��$N�㽫$n" HIY "������ǰ��"
                              "���Ľ���" + name + "����ྫҪ��$n"
                              HIY "һ����һ�߲�ס�ĵ�ͷ��";
                        break;

                default :
                        msg = "$N����һЦ����$n" HIY "�޵�������"
                              "����������������" +
                              to_chinese(sk1) + "�����裬�ұ㴫��"
                              "��" + name + "���кη�����˵���ֻ"
                              "��$N�ӻ�������һ����Ϊ�žɵ�С����"
                              "��ָ������һ�ζ�$n" HIY "��ϸ����"
                              "��$n" HIY "�����˼���ã���������";
                        break;
                }
        }
        message_sort(HIY "\n" + msg + "\n\n" NOR, ob, who);

        // ѧ��������
        who->add(perform, 1);

        // ������ʾ��Ϣ
        tell_object(who, HIC "��ѧ���ˡ�" HIW + name +
                         HIC "����\n" NOR);

        // �������Ӧ���书����
        if (stringp(sk1) && who->can_improve_skill(sk1))
                who->improve_skill(sk1, 1500000);

        if (stringp(sk2) && who->can_improve_skill(sk2))
                who->improve_skill(sk2, 1500000);

        if (stringp(sk3) && who->can_improve_skill(sk3))
                who->improve_skill(sk3, 1500000);

        if (stringp(sk4) && who->can_improve_skill(sk4))
                who->improve_skill(sk4, 1500000);

        if (stringp(sk5) && who->can_improve_skill(sk5))
                who->improve_skill(sk5, 1500000);

        // ������ skill �Ļ�������
        for (i = 0; i < sizeof(valid_types); i++)
        {
                if (SKILL_D(sk1)->valid_enable(valid_types[i])
                   && who->can_improve_skill(valid_types[i]))
                        who->improve_skill(valid_types[i], 1500000);
        }

        // ������ѧ�����ȼ�
        who->improve_skill("martial-cognize", 3500000);

        // �������ɹ���ֵ
        if (intp(gongxian) && gongxian > 0)
                who->add("gongxian", -gongxian);

        tell_object(who, "\n");

        // ���Ļش���Ϣ
        if (stringp(msg2 = b["msg2"]))
        {
                msg = msg2;
        } else
        {
                // ���Ļش���Ϣ
                switch (random(5))
                {
                case 0 :
                        msg = "�ղŵ���ʽ���������˶��٣�";
                        break;

                case 1 :
                        msg = "��ʽ������ˣ����Լ���ȥ����ɡ�";
                        break;

                case 2 :
                        msg = "�ղ��������ڵ�ȫ�Ǹ��еľ��⣬�ɼ����ˡ�";
                        break;

                case 3 :
                        msg = "��������ȥ�����ڼ���ϰ�������������硣";
                        break;

                default :
                        msg = "������ʵ�������ӣ����Լ���ȥ��ϰ�ɡ�";
                        break;
                }
        }
        return msg;
}

// ����ķ���
public mixed give_item(object who, object ob, mapping b)
{
        object obj, owner;              // �������Ʒ��ӵ����
        string item;                    // ������Ʒ�� base_name
        string msg;                     // ����ĳЩ������Ϣ������
        string sk1, sk2, sk3;           // ����Ҫ���书����
        int lv1, lv2, lv3;              // ����Ӧ���书�ȼ�
        int free;                       // �Ƿ�Ϊ������Ʒ����
        int master;                     // �Ƿ�ֻ��ֱ�����Ӳ�����ȡ
        int generation;                 // �����еı���Ҫ��
        string family;                  // ������Ʒ�ߵ�����
        int gongxian, shen;             // ����Ĺ��׼���
        string temp1, temp2, temp3;     // Ҫ��Ľ��̼�¼
        string tmsg1, tmsg2, tmsg3;     // Ҫ��Ľ��̼�¼�Ļش���Ϣ

        // ���û��ָ�������򷵻�
        if (! stringp(item = b["item"]))
                return 0;

        // �ж��������ɣ���Ϊ����Ӧ��� free ����
        //if (! intp(free = b["free"]) || free <= 0)
        //{
                family = ob->query("family/family_name");

                if (who->query("family/family_name") != family)
                        return RANK_D->query_respect(who) + "����" +
                               family + "����ԨԴ����֪�˻��Ӻ�˵��";
        //}

        // ���Ҷ�Ӧ�� base_name �������
        obj = find_object(item);

        if (! obj)
                obj = load_object(item);

        if (! obj)
                return "�Ƕ������˵����⣬���������ʦ����������";

        // �ж�ʦ�У������ master ��������ֻ��ֱ�����Ӳ�����ȡ
        if (intp(master = b["master"])
           && master > 0
           && who->query("family/master_id") != ob->query("id"))
                return "ֻ���ҵĵ��Ӳ���ʹ��" + obj->name() + CYN
                       "���㻹���߰ɡ�" NOR;

        // �ж����ɱ��ݣ������� master ��������Ӧ��ȱʡ
        if (intp(generation = b["gen"])
           && generation > 0
           && who->query("family/generation") > generation)
                return "ƾ����" + who->query("family/family_name") +
                       "�еĵ�λ�������������ҽ�" + obj->name() + CYN
                       "�����㡣" NOR;

        // �ж���������Ҫ��
        if (intp(shen = b["shen"]))
        {
                // ���Ҫ��Ϊ���������������ж�
                if (shen < 0 && who->query("shen") > shen)
                        return "�ߣ������������Ĵ�����֮������"
                               "������" + obj->name() + CYN "Ҳ"
                               "�����á�" NOR;

                // ���Ҫ��Ϊ����������С���ж�
                if (shen > 0 && who->query("shen") < shen)
                        return "��Ŀǰ�������������²�������" +
                               obj->name() + CYN "��ʱ�����ܽ�"
                               "���㡣" NOR;
        }

        // �ж��ض��Ľ��̼�¼Ҫ��
        if (stringp(temp1 = b["temp1"]) && ! who->query(temp1))
        {
                if (stringp(tmsg1 = b["tmsg1"]))
                        return tmsg1;
                else
                        return "����ĳЩ��Եδ������" + obj->name() +
                               CYN "��ʱ�����ܽ����㡣" NOR;
        }

        if (stringp(temp2 = b["temp2"]) && ! who->query(temp2))
        {
                if (stringp(tmsg2 = b["tmsg2"]))
                        return tmsg2;
                else
                        return "����ĳЩ��Եδ������" + obj->name() +
                               CYN "��ʱ�����ܽ����㡣" NOR;
        }

        if (stringp(temp3 = b["temp3"]) && ! who->query(temp3))
        {
                if (stringp(tmsg3 = b["tmsg3"]))
                        return tmsg3;
                else
                        return "����ĳЩ��Եδ������" + obj->name() +
                               CYN "��ʱ�����ܽ����㡣" NOR;
        }

        // �ж��ض����书����
        if (stringp(sk1 = b["sk1"]) && intp(lv1 = b["lv1"]))
        {
                if (who->query_skill(sk1, 1) <= 0)
                        return "����" + to_chinese(sk1) + "��δ��"
                               "ѧ������" + obj->name() + CYN "��"
                               "�к��ã�" NOR;

                if (who->query_skill(sk1, 1) < lv1)
                        return "���" + to_chinese(sk1) + "���δ"
                               "������������" + obj->name() + CYN
                               "Ҳû�á�" NOR;
        }

        if (stringp(sk2 = b["sk2"]) && intp(lv2 = b["lv2"]))
        {
                if (who->query_skill(sk2, 1) <= 0)
                        return "����" + to_chinese(sk2) + "��δ��"
                               "ѧ������" + obj->name() + CYN "��"
                               "�к��ã�" NOR;

                if (who->query_skill(sk2, 1) < lv2)
                        return "���" + to_chinese(sk2) + "���δ"
                               "������������" + obj->name() + CYN
                               "Ҳû�á�" NOR;
        }

        if (stringp(sk3 = b["sk3"]) && intp(lv3 = b["lv3"]))
        {
                if (who->query_skill(sk3, 1) <= 0)
                        return "����" + to_chinese(sk3) + "��δ��"
                               "ѧ������" + obj->name() + CYN "��"
                               "�к��ã�" NOR;

                if (who->query_skill(sk3, 1) < lv3)
                        return "���" + to_chinese(sk3) + "���δ"
                               "������������" + obj->name() + CYN
                               "Ҳû�á�" NOR;
        }

        // Ѱ�Ҹ������������
	owner = environment(obj);
        while (owner)
	{
                if (owner->is_character() || ! environment(owner))
                        break;

		owner = environment(owner);
	}

        if (owner == who)
                return "��" + obj->query("unit") + obj->name() +
                       CYN "����������������ô����ô��������"
                       "���ˣ�" NOR;

        if (objectp(owner) && owner != ob)
        {
                if (! owner->is_character())
                        return "��" + obj->query("unit") + obj->name() +
                               CYN "���Ѿ����ȥ�ˣ��㻹�Ǹ���ʱ����"
                               "���ɡ�" NOR;

                if (owner->query("family/family_name") == family)
                        return "��" + obj->query("unit") + obj->name() +
                               CYN "���������ɵ�" + owner->name() +
                               "���ã�������Ҫ��ȥ�����ɡ�" NOR;
                else
                if (owner->query("family/family_name") == who->query("family/family_name"))
                        return "��" + obj->query("unit") + obj->name() +
                               CYN "���������ɵ�" + owner->name() +
                               "���ã����Լ�ȥ����Ҫ�ɡ�" NOR;
                else
                        return "��" + obj->query("unit") + obj->name() +
                               CYN "����������" + owner->name() +
                               "���У���ȥ����ȡ�����ɡ�" NOR;
        }

        // �ж����ɹ��׵�Ҫ��
        if (intp(gongxian = b["gongxian"])
           && gongxian > 0
           && who->query("gongxian") < gongxian)
                return "��Ϊ" + who->query("family/family_name") +
                       "�����Ĺ��ײ�������" + obj->name() + CYN
                       "��ʱ�����ܽ����㡣" NOR;

        // ���ת�ƣ��������ʾ��Ϣ
        message_vision("$N�ó�" + obj->name() + "(" +
                       obj->query("id") + ")��$n��\n" NOR, ob, who);
        obj->move(who, 1);

        // �������ɹ���ֵ
        if (intp(gongxian) && gongxian > 0)
                who->add("gongxian", -gongxian);

        // ���Ļش���ʾ��Ϣ
        if (! stringp(msg = b["msg"]))
                msg = "��Ȼ����������" + obj->query("unit") +
                      obj->name() + CYN "�����ʱ��ȥ�ɡ�" NOR;

        return msg;
}
