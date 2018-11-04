// corpse.c
// Updated by Doing

inherit ITEM;
inherit F_CUTABLE;

int decayed;
static int not_cut = 0;

void create()
{
	set_name("����ʬ��", ({ "corpse" }));
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("default_clone", "/clone/misc/part");
                set("parts", ([
                        "left arm" : ({ 0, "��", "���", "�ֱ�", "arm",
                                        ([ "left hand": "hand" ]),
                                        "����", 0 }),
                        "left hand": ({ 1, "ֻ", "����", "����", "hand",
                                        ([ "left thumb"        : "thumb",
                                           "left forefinger"   : "forefinger",
                                           "left middle finger": "middle finger",
                                           "left ring finger"  : "ring finger",
                                           "left little finger": "little finger" ]),
                                        "����", 0 }),
                        "left thumb"         : ({ 2, "��", "���ִ�Ĵָ", "��Ĵָ", "thumb",
                                                  0, 0, 0 }),
                        "left forefinger"    : ({ 2, "��", "����ʳָ", "ʳָ", "forefinger",
                                                  0, 0, 0 }),
                        "left middle finger" : ({ 2, "��", "������ָ", "��ָ", "middle finger",
                                                  0, 0, 0 }),
                        "left ring finger"   : ({ 2, "��", "��������ָ", "����ָ", "ring finger",
                                                  0, 0, 0 }),
                        "left little finger" : ({ 2, "��", "����Сָ", "Сָ", "little finger",
                                                  0, 0, 0 }),
                        "right arm" : ({ 0, "��", "�ұ�", "�ֱ�", "arm",
                                        ([ "right hand": "hand" ]),
                                        "����", 0 }),
                        "right hand": ({ 1, "ֻ", "����", "����", "hand",
                                        ([ "right thumb"        : "thumb",
                                           "right forefinger"   : "forefinger",
                                           "right middle finger": "middle finger",
                                           "right ring finger"  : "ring finger",
                                           "right little finger": "little finger" ]),
                                        "����", 0 }),
                        "right thumb"         : ({ 2, "��", "���ִ�Ĵָ", "��Ĵָ", "thumb",
                                                   0, 0, 0 }),
                        "right forefinger"    : ({ 2, "��", "����ʳָ", "ʳָ", "forefinger",
                                                   0, 0, 0 }),
                        "right middle finger" : ({ 2, "��", "������ָ", "��ָ", "middle finger",
                                                   0, 0, 0 }),
                        "right ring finger"   : ({ 2, "��", "��������ָ", "����ָ", "ring finger",
                                                   0, 0, 0 }),
                        "right little finger" : ({ 2, "��", "����Сָ", "Сָ", "little finger",
                                                   0, 0, 0 }),
                        "left leg" : ({ 0, "��", "����", "����", "leg",
                                        ([ "left foot": "foot" ]),
                                         "����", 0 }),
                        "left foot": ({ 1, "ֻ", "���", "�˽�", "foot",
                                        ([ "left toes"        : "toes", ]),
                                        "����", 0 }),
                        "left toes": ({ 2, "��", "���ֺ", "��ֺ", "toes",
                                                       0, 0, 0 }),
                        "right leg" : ({ 0, "��", "����", "����", "leg",
                                        ([ "right foot": "foot" ]),
                                         "����", 0 }),
                        "right foot": ({ 1, "ֻ", "�ҽ�", "�˽�", "foot",
                                        ([ "right toes"        : "toes", ]),
                                        "����", 0 }),
                        "right toes": ({ 2, "��", "�ҽ�ֺ", "��ֺ", "toes",
                                                       0, 0, 0 }),
                        "head"      : ({ 0, "��", "ͷ", "��ͷ", "head",
                                        ([ "left eye"  : "left eye",
                                           "right eye" : "right eye",
                                           "nose"      : "nose",
                                           "left ear"  : "left ear",
                                           "right ear" : "right ear",
                                           "hair"      : "hair",
                                           "tongue"    : "tongue", ]),
                                        "����", "/clone/misc/head" }),
                        "left eye"  : ({ 1, "ֻ", "����", "����", "eye",
                                         0, "�ڳ�", 0, }),
                        "right eye" : ({ 1, "ֻ", "����", "����", "eye",
                                         0, "�ڳ�", 0, }),
                        "left ear"  : ({ 1, "ֻ", "���", "����", "ear",
                                         0, 0, 0, }),
                        "right ear" : ({ 1, "ֻ", "�Ҷ�", "����", "ear",
                                         0, 0, 0, }),
                        "nose"      : ({ 1, "ֻ", "����", "����", "nose",
                                         0, 0, 0, }),
                        "hair"      : ({ 1, "��", "ͷ��", "ͷ��", 0,
                                         0, 0, "/clone/misc/hair", }),
                        "tongue"    : ({ 1, "��", "��ͷ", "��ͷ", 0,
                                         0, 0, 0, }),
                        "genitals"  : ({ 1, "��", "��ֳ��", 0, 0,
                                         0, 0, 0, }),
                ]));
        	set("unit", "��" );
                set("main_part_level", 0);
        }
        
	set("long", "����һ������ʬ�塣\n");
	decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 60, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

string long() { return ::long() + extra_desc(); }

void decay(int phase)
{
        string msg;
        object env;

        env = environment();
	decayed = phase;
	switch (phase)
        {
	case 1:
                set("owner_id", "unknow");
		msg =  name(1) + "��ʼ�����ˣ�����һ�����ŵĶ����\n";
                delete("victim_name");
                delete("owner_id");
		switch (query("gender"))
                {
		case "����":
			set_name("���õ���ʬ", ({ "corpse", "ʬ��" }));
                        break;

		case "Ů��":
			set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }));
                        break;

		default:
			set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }));
		}
		set("long",	"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                call_out("decay", 60, phase + 1);
		break;
	case 2:
                delete("parts");
		msg = name(1) + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n";
		set_name("��Ǭ�ĺ���", ({ "skeleton", "����" }) );
		set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                call_out("decay", 30, phase + 1);
		break;
	case 3:
		msg = "һ��紵������" + name(1) + "���ɹǻҴ�ɢ�ˡ�\n";
		if( env )
                        all_inventory(this_object())->move(env);
                tell_room(env, msg);
		destruct(this_object());
		return;
	}

        while (env && env->is_character())
                env = environment(env);

        if (env) tell_room(env, msg);
}

int do_cut(object me, string arg)
{
        object ob;

        if (not_cut)
                return 0;

        if (! ::do_cut(me, arg))
                return 0;

        if (! objectp(ob = query_temp("handing")))
                return 1;

        if (arg != "right hand" &&
            arg != "right thumb" &&
            arg != "right middle finger")
                return 1;

        delete_temp("handing");
        message("vision", "��ž����һ����" + ob->name() + "����������\n",
                          environment());
        ob->move(environment());
        return 1;
}

int make_corpse(object victim, object killer)
{
        int i;
        object env;
        object aob, dob;
        object *inv;

        set_name(victim->name(1) + "��ʬ��", ({ "corpse" }));
        set("long", victim->long()
                + "Ȼ����" + gender_pronoun(victim->query("gender"))
                + "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
        set("class", victim->query("class"));
        set("age", victim->query("age")); 
        set("gender", victim->query("gender"));
        set("victim_name", victim->name(1));
        set_weight(victim->query_weight());
        set_max_encumbrance(victim->query_max_encumbrance());
        env = environment(victim);
        while (environment(env)) env = environment(env);
        move(env);
        set_temp("handing", victim->query_temp("handing"));
        if (victim->query("can_speak"))
        {
                set("owner_id", victim->query("id"));
                set("is_player", userp(victim));
                set("defeated_by", dob = victim->query_defeated_by());
                set("defeated_by_who", victim->query_defeated_by_who());
                if (objectp(killer))
                        set("killed_by", killer->query("id"));
                // ����Ϊ�˰�����Ƶ�
                if (! objectp(dob)) dob = killer;
                if (objectp(dob) &&
                    objectp(aob = dob->query_temp("quest/assist")))
                {
                        // �����ڰ���ĳ��(aob)�����ĳ�˵�ȷ��ɱ
                        // �����˵Ļ������Ҽ�¼֮��
                        if (aob->is_killing(victim->query("id")))
                                // ��¼���˰����Ķ���
                                set("assist", aob);
                }
        } else
        {
                // can not cut can_speak object
                not_cut = 1;
        }
 
        if (victim->query("class") == "bonze")
                set("no_cut/hair", "��û��ͷ�����������ٳ����������������ˡ�\n");

        switch (victim->query("gender"))
        {
        case "Ů��":
                set("no_cut/genitals", "������ˣ������һ��Ůʬ");
                break;

        case "����":
                break;

        case "����":
                set("no_cut/genitals", "������ˣ���λ��ǰ���Ѿ�����"
                                       "�����ˣ��㲻���ٲ����ˡ�\n");
                break;
        default:
                set("no_cut/genitals", "������ˣ��ⲻ���˵�ʬ�塣\n");
                break;
        }

        // Don't let wizard left illegal items in their corpses.
        if (! wizardp(victim))
        {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while (i--)
                {
                        if ((string)inv[i]->query("equipped") == "worn")
                        {
                                inv[i]->move(this_object());
                                if (! inv[i]->wear())
                                        inv[i]->move(environment(victim));
                        } else
                                inv[i]->move(this_object());
                } 
        }
        return 1;
}
