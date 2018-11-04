// ITEM Made by player(���:lingling) /data/item/l/lingling-xiandan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 10 09:42:31 2003
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("���ͨ���ɵ�[2;37;0m", ({ "xiandan" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ�Ի���
��˵�˵������칬�е���Ʒ�����˳��˿���ƽ�����ǡ�[2;37;0m
����Ե�Ͽ���һ��С�֣����(lingling)
");
	set("value", 800000);
	set("point", 7);
	set("material", "iron");
	set("wear_msg", "[33m$N[33mװ�����ͨ���ɵ�[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m���������ͨ���ɵ�[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
