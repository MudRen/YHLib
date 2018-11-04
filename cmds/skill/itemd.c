// itemd.c
// Update by Vin for Heros.cn

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <command.h>

void create() { seteuid(getuid()); }

// ����������͸����Ʒ�б���������Ʒ��base_name
string *imbue_list = ({
        "/clone/fam/gift/int3",
        "/clone/fam/gift/con3",
        "/clone/fam/gift/str3",
        "/clone/fam/gift/dex3",
        "/clone/fam/item/bless_water",
        "/clone/fam/etc/lv7d",
        "/clone/fam/etc/lv7c",
});

// ����Ĵ�����������ޣ����ÿ��IMBUE�Ժ�ȡ0-IMBUE���������
// �����������ֵ����IMBUE���ճɹ���
#define RANDOM_IMBUE_OK         100

// ÿ�ν�����Ҫʥ���Ĵ���
#define SAN_PER_IMBUE           5

// ɱ�����Ժ�Ľ���
void killer_reward(object me, object victim, object item)
{
        int exp;
        mapping o;
        string my_id;

        if (! me || ! victim)
                return;

        if (! victim->query("can_speak"))
                // only human does effect
                return;

        // record for this weapon
	if (victim->is_not_bad())  item->add("combat/WPK_NOTBAD", 1);
	if (victim->is_not_good()) item->add("combat/WPK_NOTGOOD", 1);
	if (victim->is_good())     item->add("combat/WPK_GOOD", 1);
	if (victim->is_bad())      item->add("combat/WPK_BAD", 1);

        if (userp(victim))
                item->add("combat/PKS", 1);
        else
                item->add("combat/MKS", 1);

        exp = victim->query("combat_exp");
        if (exp < 10000 || me->query("combat_exp") < exp * 4 / 5)
                return;

        exp /= 10000;
        if (exp > 250) exp = 100 + (exp - 250) / 16; else
        if (exp > 50) exp = 50 + (exp - 50) / 4;
        my_id = me->query("id");
        o = item->query("owner");
        if (! o) o = ([ ]);
        if (! undefinedp(o[my_id]) || sizeof(o) < 12)
                o[my_id] += exp;
        else
        {
                // Too much owner, I must remove one owner
                int i;
                int lowest;
                string *ks;

                lowest = 0;
                ks = keys(o);
                for (i = 1; i < sizeof(ks); i++)
                        if (o[ks[lowest]] > o[ks[i]])
                                lowest = i;
                map_delete(o, ks[lowest]);
                o += ([ my_id : exp ]);
        }
        item->set("owner", o);
}

// �ٻ���Ʒ
int receive_summon(object me, object item)
{
        object env;
        object temp;
        int type;

        if ((env = environment(item)) && env == me)
        {
                tell_object(me, item->name() + "������������"
                            "����ٻ���ʲô����\n");
                return 1;
        }

        if (me->query("jingli") < 200)
        {
                tell_object(me, "����ͼ����" + item->name() +
                            "���������Խ��뾳�磬�����Ǿ������á�\n");
                return 0;
        }
        me->add("jingli", -200);

        if (item->query("id") == "qingtian")
        {
              message_sort(HIM "\nֻ�����ܽ��ɢ�������ƶ�䣬Զ���з�����ƣ�������Ϸ������"
                           "��������������$N" HIM "һ����Х��" + item->query("name") + HIM
                           "�ƿն��� ������\n\n" NOR, me); 
        }
        else

              message_vision(HIW "$N" HIW "ͻȻ���һ��������������"
                             "һץ����Ȼ�����ܲ�������������\n\n" NOR, me);

        if (env == environment(me))
        {
                message_vision(HIW "ֻ�����ϵ�" + item->name() +
                               HIW "Ӧ�����𣬷�Ծ��$N" HIW
                               "�����У�\n\n" NOR, me);
        } else
        {
                type = random(3);
                if (env)
                {
                        if (env->is_character() && environment(env))
                                        env = environment(env);

                        switch (type)
                        {
                        case 0:
                                message("vision", HIW "����д�������������"
                                        "����Ȼ����������" + item->name() +
					HIW "�ڿն���"
                                        "��ʧ������\n\n" NOR, env);
                                break;
                        case 1:
                                message("vision", HIC "һ�����������"
                                        "���ֶ���" + item->name() + HIC "��ֻ��" +
					item->name() + HIC "���������ƿն�"
					"�ߡ�\n\n" NOR, env);
                                break;
                        default:
                                message("vision", HIY "��Ȼ�������أ���������" +
                                        item->name() + HIY "�����ʵĶ������£�����һ"
					"�����ת˲������\n\n" NOR, env);
                                break;
                        }

                        if (interactive(env = environment(item)))
                        {
                                tell_object(env, HIM + item->name() +
                                                 HIM "��Ȼ�����ȥ�ˣ�\n" NOR);
                        }
                }

                switch (type)
                {
                case 0:
                        message_vision(HIW "һ��" HIR "����" HIW "��"
                                       "���绮�Ƴ��գ�" + item->name() + HIW
                                       "�������������$N" HIW "�����У�\n\n" NOR, me);
                        break;
                case 1:
                        if (item->query("id") == "qingtian")break;

                        message_vision(HIW "һ��" HIY "����" HIW "ɨ��"
                                       "��գ�ֻ��" + item->name() + HIW
					"������$N" HIW "�����У�\n\n" NOR, me);
                        break;
                default:
                        message_vision(HIW "ֻ��" + item->name() + HIW "�������죬��"
                                       "����ʣ�Ю�ƴ���ͻ����$N"
                                       HIW "�����У�\n\n" NOR, me);
                        break;
                }
        }

        // ȡ��no_get����
        item->delete_temp("stab_by");
        item->delete("no_get");

        item->move(me, 1);
        if (environment(item) != me)
                return 1;

        if (item->query("armor_type"))
        {
                // is armor
                temp = me->query_temp("armor/" + item->query("armor_type"));
                if (temp) temp->unequip();
                WEAR_CMD->do_wear(me, item);
        } else
        if (item->query("skill_type"))
        {
                if (temp = me->query_temp("weapon"))
                        temp->unequip();
                if (temp = me->query_temp("secondary_weapon"))
                        temp->unequip();
                WIELD_CMD->do_wield(me, item);
        }

        return 1;
}

// ������Ʒ
int hide_anywhere(object me, object item)
{
        if (item->item_owner() != me->query("id"))
                return 0;

        if (me->query("jingli") < 100)
        {
                tell_object(me, "����ͼ��" + item->name() +
                            "��ȥ�����Ǿ������ã����Է�������������\n");
                return 0;
        }
        me->add("jingli", -100);

        message_vision(HIM "$N" HIM "����һ��" + item->name() +
                       HIM "����Ȼ�����ټ���\n", me);
        destruct(item);
        return 1;
}

// ׷Ѱ��Ʒ
int receive_miss(object me, object item)
{
        object env;

        env = environment(item);

        if (env == environment(me))
        {
                write("�����" + item->name() + "����ɶ��\n");
                return 0;
        }

        if (env == me)
        {
                write("������" + item->name() + "�����˰���Ĵ���\n");
                return 0;
        }

        if (! objectp(env) || userp(env) || environment(env))
        {
                write("����ͼ��Ӧ" + item->name() + "�����Ǹо��ǳ�����ã��\n");
                return 0;
        }

        if (! wizardp(me) && ! env->query("outdoors"))
        {
                write("ڤڤ�����Ӧ��" + item->name() + "�������ƺ����Ե������\n");
                return 0;
        }

        message("vision", me->name() + "������˼������֪��Ҫ��Щʲô��\n",
                environment(me), ({ me }));
        if (me->query("jingli") < 400)
        {
                write("�����" + item->name() + "�ĸо��൱"
                      "Ʈ���������������ã����Ը�Ӧ��\n");
                return 0;
        }

        // ���ľ���
        me->add("jingli", -300 - random(100));
        message_vision(HIM "$N" HIM "���������дʣ�ת˲���һ�����绮"
                       "����$N" HIM "�ݲʺ���ߡ�\n" NOR, me);
        tell_object(me, "��׷Ѱ" + item->name() + "��ȥ��\n");
        me->move(environment(item));
        message("vision", HIM "һ���ʺ绮����ʣ�" + me->name() +
                HIM "ƮȻ���£��������ɡ�\n" NOR, environment(me), ({ me }));
        tell_object(me, HIM "��׷Ѱ����" + item->name() +
                    HIM "�����¶ݹ⡣\n" NOR);
        return 1;
}

// ���ڵ���
int do_stab(object me, object item)
{
        if (! item->is_weapon() && item->query("armor_type") != "hands")
                return notify_fail(item->name() + "Ҳ�ܲ��ڵ��ϣ�\n");

        if (! environment(me)->query("outdoors") &&
            ! wizardp(me))
                return notify_fail("��������Ūʲô��\n");

        item->set("no_get", bind((: call_other, __FILE__, "do_get_item", item :), item));
        item->set_temp("stab_by", me->query("id"));

        message_vision(WHT "\n$N" WHT "���ֽ�" + item->name() + NOR +
                       WHT "������һ�壬��������㶡�һ�����졣\n\n" NOR, me);
        item->move(environment(me));
        return 1;
}

// ��ȡ��Ʒʱ���
mixed do_get_item(object item)
{
        object me;

        if (! objectp(me = this_player()))
                return 1;

        if (me->query("id") != item->query_temp("stab_by") &&
            me->query("id") != item->item_owner())
                return "����ͼ��" + item->name() + "����ȴ"
                       "�������·�������������һ�㣬�޷�������\n";

        message_vision(HIW "\n$N" HIW "���ַ���" + item->name() +
                       HIW "��������ʱֻ�����͡���һ��������һ��"
                       "������\n\n" NOR, me);
        item->delete_temp("stab_by");
        item->delete("no_get");
        item->move(me, 1);
        return "";
}

// �������⹦��
mixed do_touch(object me, object item)
{
        string msg;
        object ob;
        object *obs;
        mapping my;

        if (me->query("id") != item->item_owner())
        {
                message_vision(HIR "\n$N���ᴥ��" + item->name() +
                               HIR "��ͻȻ��ȫ��һ��������������"
                               "���ܵ����\n" NOR, me);
                me->receive_damage("qi", 50 + random(50));
                return 1;
        }

        if (me->query("jingli") < 200)
        {
                me->set("jingli", 0);
                return notify_fail(CYN "\n������" + item->name() +
                                   CYN "��ã�����һ����̾��\n" NOR);
        }

        switch (random(3))
        {
        case 0:
                msg = CYN "\n$N" CYN "����һ��$n" CYN "������"
                      "������������������\n" NOR;
                break;
        case 1:
                msg = CYN "\n$N" CYN "���ḧ��$n" CYN "������"
                      "��һ�ף�$n" CYN "�������죬���Ժ�֮��\n" NOR;
                break;
        default:
                msg = CYN "\n$N" CYN "��Ȼһ����̾���ḧ$n"
                      CYN "����˼���ã������п���ǧ��\n" NOR;
                break;
        }

        switch (random(3))
        {
        case 0:
                msg += HIM "��Ȼֻ��$n" HIM "����һ���⻪��"
                       "��Ծ����ɢ��ǧ�����롣\n" NOR;
                break;
        case 1:
                msg += HIM "����$n" HIM "һ�����������Ʋ���"
                       "��ֱ���뵽����ķ���ȥ��\n" NOR;
                break;
        default:
                msg += HIM "��ʱ��$n" HIM "��â���䣬������"
                       "����ʣ��Ƶ�������Ŀ�ӡ�\n" NOR;
                break;
        }

        me->add("jingli", -150);
        msg = replace_string(msg, "$n", item->name());
        message_vision(msg, me);

        if (random(1000) == 1 || wizardp(me))
        {
                obs = filter_array(all_inventory(environment(me)), (: userp :));
                foreach (ob in obs)
                {
                        my = ob->query_entire_dbase();
                        my["jing"]   = my["eff_jing"] = my["max_jing"];
                        my["qi"]     = my["eff_qi"]   = my["max_qi"];
                        my["neili"]  = my["max_neili"];
                        my["jingli"] = my["max_jingli"];
                        ob->set_temp("nopoison", 1);
                }
                tell_object(obs, HIC "��е�һ���º͵�����Ϯ��������"
                                "�������һ�㡣\n" NOR);
        } else
        if (me->query("neili") < me->query("max_neili"))
        {
                me->set("neili", me->query("max_neili"));
                tell_object(me, HIC "��ֻ��һ������������ȽȽ����"
                                "˵�����������\n" NOR);
        }
        return 1;
}

// ʥ����Ʒ
int do_san(object me, object item)
{
        string my_id;
        int count;
        int san;

        if (! item->query("skill_type") && item->query("armor_type") != "hands")
        {
                // ��װ���ࣿ
                return notify_fail("װ�����ڻ��޷�ʥ����\n");
        }

        // �������ʥ��
        if (item->query("magic/power") > 0)
                return notify_fail("����" + item->name() + "������"
                                   "�Ѿ��õ��˳�ֵķ����ˡ�\n");

        if (item->query("magic/imbue_ok"))
                return notify_fail("����" + item->name() + "��Ǳ��"
                                   "�Ѿ�����ھ��ˣ�����ֻ����Ҫ��"
                                   "��һ���ںϡ�\n");

        my_id = me->query("id");

        count = sizeof(item->query("magic/do_san"));
        if (item->query("magic/imbue_ob"))
                return notify_fail("����" + item->name() + "�Ѿ�����ֵ�ʥ"
                                   "���ˣ���Ҫ���������Խ�һ��ĥ����\n");

        if (item->query("magic/do_san/" + my_id))
                return notify_fail("���Ѿ�Ϊ" + item->name() + "ʥ�����ˣ�"
                                   "�Ƿ����������޷�������ȫ���ա�\n��"
                                   "�б�ҪѰ�����˰����Լ���ʥ����\n");

        if (item->item_owner() == my_id)
        {
                if (! count)
                        return notify_fail("��Ӧ����Ѱ����λ����Э��������ʥ��" +
                                           item->name() + "��\n");

                if (count < SAN_PER_IMBUE - 1)
                        return notify_fail("��Ӧ����Ѱ��" +
                                           chinese_number(SAN_PER_IMBUE - 1 - count) +
                                           "λ��������ʥ��" + item->name() + "��\n");
        } else
        {
                if (count >= SAN_PER_IMBUE - 1)
                        return notify_fail("�����Ҫ��������Ϊ��ʥ��������������ˡ�\n");
        }

        if (me->query("neili") < me->query("max_neili") * 9 / 10)
                return notify_fail("�����������������棬����óȻ���ã�\n");

        if (me->query("jingli") < me->query("max_jingli") * 9 / 10)
                return notify_fail("�����ھ������ã�����óȻ���ã�\n");

        if (me->query_skill("force") < 300)
                return notify_fail("����ڹ�����������ʵ������óȻʥ����\n");

        if (me->query("max_neili") < 8000)
                return notify_fail("�㳢������һ���������޷�˳"
                                   "������һ�����죬����ʩչ���������\n");

        if (me->query("max_jingli") < 1000)
                return notify_fail("����ͼ�������þ��������Ǹо�����Ƿȱ��\n");

        message_sort(HIM "\n$N" HIM "���ḧ��$n" HIM "����ָ�������ϣ�ͬ"
                     "ʱ��ת���������������澭����ԴԴ������������ע"
                     "��$n" HIM "������ֻ����������$n" HIM
                     "����Ȼ�������������ܡ�\n" NOR, me, item);

        if (me->query("max_neili") < me->query_neili_limit() - 400)
        {
                if (random(2) == 1)
                {
                        // ����δ������
                        message_vision(HIR "$N" HIR "��ɫ��Ȼ���˱䡣\n" NOR,
                                       me);
                        tell_object(me, HIC "���Ȼ���õ�����Ϣ��Щ���ҡ�\n" NOR);
                } else
                {
                        message_vision(HIR "$N" HIR "��Ȼ�ƺ�һ������"
                                       "��ɲʱ�����죡\n" NOR, me);
                        tell_object(me, HIC "��е����������������δ����"
                                    "���������������������ڹ�������\n" NOR);
                        tell_object(me, HIC "��Ļ����ڹ��½��ˡ�\n");
                        me->set_skill("force", me->query_skill("force", 1) - 10 - random(5));
                        return 1;
                }
        }

        // ͳ��IMBUE���Ĵ��������������㱾��MAX_NEILI/JINGLI������
        san = item->query("magic/imbue");

        me->add("max_neili", -(san + 5));
        me->add("neili", -(san * 10 + 100));
        me->add("max_jingli", -(san * 5 + 50));
        me->add("jingli", -(san * 5 + 50));
        item->set("magic/do_san/" + my_id, me->name(1));
        me->start_busy(1);

        if (item->item_owner() == my_id)
        {
                tell_object(me, HIW "������Ƭ�̣�����" + item->name() +
                            HIW "�ƺ��������ԣ���Ծ���ݣ�����΢΢һЦ��\n" NOR);
                message("vision", HIW + me->name() + HIW "��Ȼ"
                        "΢΢һЦ��\n" HIW, environment(me), ({ me }));

                // ѡ��һ����Ҫimbue����Ʒ
                item->set("magic/imbue_ob", imbue_list[random(sizeof(imbue_list))]);
        }
        return 1;
}

// ��͸��Ʒ
int do_imbue(object me, object item, object imbue)
{
        if (item->query("magic/power") > 0)
                return notify_fail("����" + item->name() + "������"
                                   "�Ѿ��õ��˳�ֵķ����ˡ�\n");

        if (item->query("magic/imbue_ok"))
                return notify_fail("����" + item->name() + "��Ǳ��"
                                   "�Ѿ�����ھ��ˣ�����ֻ����Ҫ��"
                                   "��һ���ںϡ�\n");

        if (sizeof(item->query("magic/do_san")) < SAN_PER_IMBUE)
                return notify_fail("������ȶ�" + item->name() +
                                   "���г�ֵ�ʥ�����С�\n");

        if (base_name(imbue) != item->query("magic/imbue_ob"))
                return notify_fail(item->name() + "���ڲ���Ҫ��" +
                                   imbue->name() + "�����롣\n");

        message_sort(HIM "$N" HIM "����һ����������������һ���˪��ֻ����ס$n" +
                     imbue->name() +
                     HIM "����Ȼ���ڻ������ģ���Ө��͸��$N"
                     HIM "����һ�ӣ���һ����Һ����$n" HIM
                     "�ϣ���ʱ������������������ʣ������˸��\n" NOR,
                     me, item);

        tell_object(me, "�㽫" + imbue->name() + "��Ч��������" +
                    item->name() + "��\n");
        item->delete("magic/do_san");
        item->delete("magic/imbue_ob");
        destruct(imbue);
        me->start_busy(1);

        item->add("magic/imbue", 1);
        if (random(item->query("magic/imbue")) >= RANDOM_IMBUE_OK)
        {
                // ��͸���
                tell_object(me, HIG "���Ȼ�������е�" + item->name() +
                            HIG "��һ��ԾԾ���Եĸо����ƺ��ڴ���ʲô��\n" NOR);
                item->set("magic/imbue_ok", 1);
        }

        return 1;
}

// ��Ƕ��Ʒ
int do_enchase(object me, object item, object tessera)
{
        if (item->query("magic/power") > 0)
                return notify_fail("����" + item->name() + "������"
                                   "�Ѿ��õ��˳�ֵķ����ˡ�\n");

        if (! item->query("magic/imbue_ok"))
                return notify_fail("����" + item->name() + "��Ǳ��"
                                   "��û�г�ֵļ�����δ����Ƕ��ʱ��\n");

        if (! tessera->query("can_be_enchased"))
                return notify_fail(tessera->name() + "����û"
                                   "��������Ƕ�ɡ�\n");

        if (! mapp(tessera->query("magic")))
                return notify_fail(tessera->name() + "���ܷ���ħ����"
                                   "û�б�Ҫ��Ƕ��" + item->name() + "���档\n");

        if (me->query_skill("certosina", 1) < 200)
                return notify_fail("����������Ƕ���ջ�����"
                                   "��죬����óȻ���֡�\n");

        message_sort(HIM "��������һ����$N" HIM "��" + tessera->name() +
                     HIM "��Ƕ����$n" HIM "���棬ֻ��$n" HIM
                     "���������Թ���һ������Ĺ�â����"
                     "�����ƽ����˵������ƽ����\n" NOR, me, item);
        tell_object(me, HIC "�����" + item->name() + HIC "������"
                    "���������ı仯��\n" NOR);
        item->set("magic/power", tessera->query("magic/power"));
       	item->set("magic/type", tessera->query("magic/type"));
        item->set("magic/tessera", tessera->name());
        item->save();
        destruct(tessera);

        // ������Ϣ
        CHANNEL_D->do_channel(this_object(), "rumor",
                              "��˵��Ʒ" + item->name() + HIM +
                              "�������˼䡣");

        me->start_busy(1);
        return 1;
}

// 10��������������
mixed weapon10lv_hit_ob(object me, object victim, object weapon, int damage_bonus)
{
        mapping magic;
        int jingjia;
        int power, resistance;
        int damage;
        string msg;

        // ����ħ��Ч��
        magic = weapon->query("magic");
        power = magic["power"];
        damage = 0;
        resistance = 0;
        //jingjia = me->query("jiajing");
        jingjia = me->query("jiali") / 3;
      
        switch (magic["type"])
        {
        case "lighting":
                // ���繥�����˺�����++����+
                resistance = victim->query_temp("apply/resistance/lighting");
                damage = (power + jingjia) * 200 / (100 + resistance);
                switch (random(3))
                {
                case 0:
                        msg = HIY + weapon->name() + HIY "�ŷ����������������⣬�������죬��$n"
                              HIY "����Ϊ֮���顣\n" NOR;
                        break;
                case 1:
                        msg = HIY "һ�����������" + weapon->name() + HIY
                              "���ҫ�۶�Ŀ����$n" HIY "�޷����ӣ������ϡ�\n" NOR;
                        break;
                default:
                        msg = HIY "����������������ף�������һ������ֱ�£�" +
                              weapon->name() + HIY "��������������ͷף����$n"
                              HIY "����������\n" NOR;
                        break;
                }

                if (victim->query("neili") > damage)
                        victim->add("neili", -damage);
                else
                        victim->set("neili", 0);

                victim->receive_damage("qi", damage);
                victim->receive_wound("qi", damage / 4);
                break;

        case "cold":
                // �䶳�������˺���++����+
                resistance = victim->query_temp("apply/resistance/cold");
                damage = (power + jingjia) * 200 / (100 + resistance);
                victim->receive_damage("jing", damage / 3);
                victim->receive_wound("jing", damage / 6);
                victim->receive_damage("qi", damage / 2);
                victim->receive_wound("qi", damage / 5);
                switch (random(3))
                {
                case 0:
                        msg = HIB + weapon->name() + HIB "����һ����ɬ�����⣬��$n"
                              HIB "����������\n" NOR;
                        break;
                case 1:
                        msg = HIB "��Ȼ��" + weapon->name() + HIB
                              "���͸��ͨ����һ��������ĺ���ŷ�������$n"
                              HIB "����ֻ��һ�䡣\n" NOR;
                        break;
                default:
                        msg = HIB "һ����Ȧ��" + weapon->name() + HIB "�����"
                              "ɭȻ������$n" HIB "���ܣ���Ȼ��Ϣ��\n" NOR;
                        break;
                }
                break;

        case "fire":
                // ���湥�����˺���+����++
                resistance = victim->query_temp("apply/resistance/fire");
                damage = (power + jingjia) * 300 / (100 + resistance);
                victim->receive_damage("jing", damage / 5);
                victim->receive_wound("jing", damage / 8);
                victim->receive_damage("qi", damage);
                victim->receive_wound("qi", damage / 2);
                switch (random(3))
                {
                case 0:
                        msg = HIR + weapon->name() + HIR "�������һ�����棬��$n"
                              HIR "�����������������ҽ�������\n" NOR;
                        break;
                case 1:
                        msg = HIR "һ������" + weapon->name() + HIR
                              "�ϱų���Ѹ�����׵Ļ���$n" HIR "�����˱��޿ɱܣ�\n" NOR;
                        break;
                default:
                        msg = HIR "һ���������" + weapon->name() + HIR "�Ϸɽ������"
                              "����ɢ������������$n" HIR "��\n" NOR;
                        break;
                }
                break;

        case "magic":
                // ħ����������ȡ��+
                resistance = victim->query_temp("apply/resistance/magic");
                damage = (power + jingjia) * 200 / (100 + resistance);
                victim->receive_damage("qi", damage);
                victim->receive_wound("qi", damage / 4);
                switch (random(3))
                {
                case 0:
                        msg = HIM + weapon->name() + HIM "����һ�������������������������$n"
                              HIM "���񲻶��������㱡�\n" NOR;
                        break;
                case 1:
                        msg = HIM "��࣡���һ����" + weapon->name() + HIM
                              "����ܸȴ��$n" HIM "�ƺ�һ����ҡ�β�����\n" NOR;
                        break;
                default:
                        msg = HIM + weapon->name() + HIM "������һ��������ͷ׵�"
                              "��Ȧ��������$n" HIM "�����·��衣\n" NOR;
                        break;
                }
                break;

        default:
                msg = "";
                break;
        }

        // ʹ��perform
        if (random(2)) return msg;
        damage = 200 + random(400);

        switch (random(6))
        {
        case 0:
                victim->receive_wound("jing", damage / 6 + random(damage / 6), me);
                return msg + HIM "$N" HIM "��Ȼ��Ц������" + weapon->name() +
                       HIM "�������⻪һ���������$n" HIM "���ڵ��У��޷��԰Ρ�\n" NOR;

        case 1:
                victim->receive_wound("jing", damage / 5 + random(damage / 5), me);
                return msg + HIC "$N" HIC "���е�" + weapon->name() + HIC "������ֹ�â��"
                       "ѣĿ���ˣ�һ�������ӳ�����ؾ���ʧɫ����$n"
                       HIC "Ŀ�ɿڴ���\n" NOR;
        case 2:
                victim->receive_wound("qi", damage / 4 + random(damage / 4), me);
                return msg + HIY "$N" HIY "����" + weapon->name() +
                       HIY "��ֻ�����һ������������$n" HIY "���¼�����Ѫ��\n" NOR;

        case 3:
                victim->receive_wound("qi", damage / 3 + random(damage / 3), me);
                return msg + HIG "$N" HIG "���ֻ���" + weapon->name() + HIG "��һȦȦ��â"
                       "Χ��$n" HIG "�����$n��Ѫ������\n" NOR;

        case 4:
                victim->receive_wound("qi", damage / 2 + random(damage / 2), me);
                return msg + HIW "$N" HIW "һ����̾��" + weapon->name() + HIW "����ݳ���"
                       "��ʱ�����㾲��$n" HIW "ֻ���������˶������˵�����ȥ��\n" NOR;

        default:
                if (me->query_temp("weapon_performing"))
                        break;
                me->start_call_out(bind((: call_other, __FILE__, "continue_attack",
                                           me, victim, weapon, 10 + random(4) :), me), 0);
        }
}

// 9��������������
mixed weapon_hit_ob(object me, object victim, object weapon, int damage_bonus)
{
        int ap;
        int dp;
        int damage;

        if (random(2)) return;

        // ����damage�������ǿ�������������ͨ������ͳһ����
        if (weapon->is_weapon())
                damage = me->query_temp("apply/damage");
        else
                damage = me->query_temp("apply/unarmed_damage");

        switch (random(8))
        {
        case 0:
                victim->receive_wound("jing", damage / 5 + random(damage / 5), me);
                return HIY "$N" HIY "�������е�" + weapon->name() + HIY
                       "���û���ҹ�����ǣ�����" HIM "��â" HIY "������"
                       "��Ϯ��$n" HIY "��\n" NOR;
        case 1:
                victim->receive_wound("qi", damage / 3 + random(damage / 3), me);
                return HIR "$N" HIR "���һ��������" + weapon->name() +
                       HIR "ңָ$n" HIR "��һ��ɱ����ʱ��$n" HIR "����"
                       "������\n" NOR;
        case 2:
                victim->receive_wound("qi", damage / 6 + random(damage / 6), me);
                victim->receive_wound("jing", damage / 10 + random(damage / 10), me);
                return HIG "$N" HIG "��ػ�ת" + weapon->name() + HIG
                       "��������̲�������" NOR + HIB "�Ǻ�" HIG "��"
                       "������$n" HIG "Ȧ�����С�\n" NOR;
        case 3:
        case 4:
        case 5:
        case 6:
                break;

        default:
                if (me->query_temp("weapon_performing"))
                        break;
                me->start_call_out(bind((: call_other, __FILE__, "continue_attack",
                                           me, victim, weapon, 5 + random(4) :), me), 0);
        }
}

// ���У�12��������
void continue_attack(object me, object victim, object weapon, int times)
{
        int i;
        string msg;
        int ap, dp;

        if (! me || ! victim || ! weapon || ! me->is_fighting(victim))
                return;

        msg  = HIW "��ʱֻ��$N" HIW "������Х������" + weapon->name() +
               HIW "��Ϊһ�壬��ʱ�亮â��ɢ����$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("martial-cognize");
        dp = victim->query_skill("parry");

        if (ap / 2 + random(ap) > dp * 2 / 3)
                msg += HIR "$n" HIR "��֮����æ���ˣ�����Ȼ�������ܣ�����"
                       "�в�������������\n" HIW "$N" HIW "��ס$n" HIW "����"
                       "������������ת����" + weapon->name() + HIW "������"
                       "ʯ���ѳ�$n" HIW "����" + chinese_number(times) + HIW
                       "�У�\n" NOR;
        else
        {
                msg += CYN "����$n" CYN "ڤ��ֵ�����$N"
                       CYN "���е����б仯ȫȻ��ס��\n" NOR;
                message_combatd(msg, me, victim);
                return;
        }
        message_combatd(msg, me, victim);

        me->set_temp("weapon_performing", 1);
        i = times;
        while (i--)
        {
                if (! me->is_fighting(victim))
                        break;

                if (! victim->is_busy() && random(2))
                        victim->start_busy(1);

                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
        }
        me->delete_temp("weapon_performing");
}

// �����;ö�
void reduce_consistence(object item)
{
        int st;
        int con;

        st = item->query("stable");

        if (st < 2)
                return;

        con = item->query("consistence");

        // ����쾧���Ƶ���������ĥ��
        if (item->query("material") == "tian jing")
                return;

        if (random(st) > (100 - con) / 12)
                return;

        if (item->add("consistence", -1) > 0)
                return;

        item->set("consistence", 0);

        if (environment(item))
                tell_object(environment(item), HIG "���" +
                            item->name() + HIG "�Ѿ��������ˡ�\n");

        item->unequip();
}

// ������Ʒȱʡ���;ö���Ϣ
void equip_setup(object item)
{
        int stable;
        mapping dbase;

        dbase = item->query_entire_dbase();
        if (undefinedp(dbase["consistence"]))
                dbase["consistence"] = 100;

        if (undefinedp(item->query("stable")))
        {
                switch (item->query("material"))
                {
                case "cloth":
                        // ��Զ������
                        stable = 0;
                        break;
                case "paper":
                        stable = 3;
                        item->set("no_repair", "�ⶫ���ҿ�û������\n");
                        break;
                case "bone":
                        stable = 8;
                        item->set("no_repear", "����������ɱ�����Ѱ���ġ�\n");
                        break;
                case "bamboo":
                case "wood":
                        stable = 10;
                        item->set("no_repair", "�ⶫ����զ����\n");
                        break;
                case "copper":
                        stable = 40;
                        break;
                case "silver":
                        stable = 40;
                        break;
                case "iron":
                        stable = 45;
                        break;
                case "gold":
                        stable = 50;
                        break;
                case "steel":
                        stable = 75;
                        break;
                case "stone":
                        stable = 80;
                        break;
                default:
                        stable = 100;
                        break;
                }

                if (! item->is_item_make())
                        stable /= 2;

                item->set("stable", stable);
        }
}
