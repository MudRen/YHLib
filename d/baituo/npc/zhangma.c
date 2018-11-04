#include <ansi.h>
inherit NPC;

string inquiry_hua();

void create()
{
        set_name("����", ({ "zhang ma", "zhang", "ma" }));
        set("gender", "Ů��" );
        set("age", 50);
        set("long", "һ��������ɣ�������š�\n");
        set("shen_type", 1);
        set("combat_exp", 500);
        set("str", 16);
        set("dex", 17);
        set("con", 17);
        set("int", 18);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                CYN "������߶�ţ��ҿ����Ľ�Ӵ��������������Ӵ��\n" NOR,
                CYN "���谵��Ĩ�˰����ᡣ\n" NOR,
                CYN "�������˵�����ҵĽ�ѽ��������Ʋ�����Ը������ˡ�\n" NOR
        }));

        set("inquiry", ([
                "��" : (: inquiry_hua :),
        ]));

        set_temp("shoe", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string inquiry_hua()
{
        object me = this_player();
        object obn;

        message_vision(CYN "����˵������λ" + RANK_D->query_respect(me) +
                       CYN "�������ҵ��׹�Ů��ȥ����ɽ��ݾ�һȥ���ᣬҲ"
                       "��֪�����ǻ\n" NOR, me );

        if(query_temp("shoe") == 0)
        {
                message_vision(CYN "�����ֵ����������Ѿ�����ȥѰ���ˣ�Ҳ��"
                               "֪����ô���ˡ�\n" NOR, me);
                return "����Ҳ��֪��������������ô���ˡ�";
        }

        message_vision(CYN "������˵�����������������ڲݴ����һֻ�廨Ь��"
                       "��Ҫ���ҵ������Ͱ�Ь���������������׵ġ�\n" HIC "��"
                       "��ӻ���""����һֻ�廨Ь�����㡣\n" NOR, me);

        obn = new("/d/baituo/obj/shoe");
        obn->move(me, 1);
        set_temp("shoe", 0);
        return "�����������Ҫ���������";
}

